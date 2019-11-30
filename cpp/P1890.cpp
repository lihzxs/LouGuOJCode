/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-11 23:54
//	Comment		:	OJ(P1890)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int CalcGCD(int a, int b)
{
	return b ? CalcGCD(b, a%b) : a;
}

typedef struct SNode
{
	int			nLeft;
	int			nRight;
	long long	nLazyFlag;
	long long	nNum;
}SNode;


void BuildTree(SNode* psTree, int nNow, int nLeft,
	int nRight, int* pnSeq)
{
	psTree[nNow].nLeft = nLeft;
	psTree[nNow].nRight = nRight;
	if (nLeft == nRight)
	{
		psTree[nNow].nNum = pnSeq[nLeft];
		return;
	}
	int		nMid;
	nMid = (nLeft + nRight) / 2;

	BuildTree(psTree, 2 * nNow, nLeft,
		nMid, pnSeq);
	BuildTree(psTree, 2 * nNow + 1, nMid + 1,
		nRight, pnSeq);

	psTree[nNow].nNum = CalcGCD(psTree[2 * nNow].nNum ,
		psTree[2 * nNow + 1].nNum);
}


int Query(SNode* psTree, int nNow, int nLeft, int nRight)
{
	if (nLeft <= psTree[nNow].nLeft && psTree[nNow].nRight <= nRight)
		return psTree[nNow].nNum;

	int			nMid;
	int			nAns = 0;
	nMid = (psTree[nNow].nLeft + psTree[nNow].nRight) / 2;

	if (nLeft <= nMid)
		nAns = CalcGCD(Query(psTree, 2 * nNow, nLeft, nRight), nAns);
	if (nRight > nMid)
		nAns = CalcGCD(Query(psTree, 2 * nNow + 1, nLeft, nRight), nAns);
	return nAns;
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nQ;
	int				nLeft;
	int				nRight;
	int				nNum;
	int*			pnSeq = NULL;
	SNode*			psTree = NULL;

	scanf("%d%d", &nInputN, &nInputM);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	psTree = (SNode*)malloc((4 * nInputN + 4) * sizeof(SNode));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	BuildTree(psTree, 1, 1, nInputN, pnSeq);


	while (nInputM--)
	{
		scanf("%d%d", &nLeft, &nRight);
		int nTemp = Query(psTree, 1, nLeft, nRight);
		printf("%d\n", nTemp);
	}

Exit0:

	return 0;
}