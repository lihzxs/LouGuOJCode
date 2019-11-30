/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-7 23:39
//	Comment		:	OJ(P2311)
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

typedef struct SNode
{
	int			nLeft;
	int			nRight;
	pair<long, int>	prAns;
}SNode;


void BuildTree(SNode* psTree, int nNow, int nLeft,
	int nRight, long* pnSeq)
{
	psTree[nNow].nLeft = nLeft;
	psTree[nNow].nRight = nRight;
	if (nLeft == nRight)
	{
		psTree[nNow].prAns = {pnSeq[nLeft], nLeft};
		return;
	}
	int		nMid;
	nMid = (nLeft + nRight) / 2;

	BuildTree(psTree, 2 * nNow, nLeft,
		nMid, pnSeq);
	BuildTree(psTree, 2 * nNow + 1, nMid + 1,
		nRight, pnSeq);

	psTree[nNow].prAns = max(psTree[2 * nNow].prAns,
		psTree[2 * nNow + 1].prAns);
}



pair<long, int> Query(SNode* psTree, int nNow, int nLeft, int nRight)
{
	if (nLeft <= psTree[nNow].nLeft && psTree[nNow].nRight <= nRight)
		return psTree[nNow].prAns;

	int			nMid;
	nMid = (psTree[nNow].nLeft + psTree[nNow].nRight) / 2;
	pair<long, int>		nL = {0,-1};
	pair<long, int>		nR = {0, -1};

	if (nLeft <= nMid)
		nL = Query(psTree, 2 * nNow, nLeft, nRight);
	if (nRight > nMid)
		nR = Query(psTree, 2 * nNow + 1, nLeft, nRight);
	return max(nL, nR);
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nQ;
	pair<long, int>				nTemp;
	int				nLeft;
	int				nRight;
	int				nNum;
	long*			pnSeq = NULL;
	SNode*			psTree = NULL;

	scanf("%d", &nInputN);

	pnSeq = (long*)malloc((nInputN + 1) * sizeof(long));
	psTree = (SNode*)malloc((4 * nInputN + 4) * sizeof(SNode));

	for (int i = 1; i <= nInputN; i++)
		scanf("%ld", pnSeq + i);

	BuildTree(psTree, 1, 1, nInputN, pnSeq);

	scanf("%d", &nInputM);
	while (nInputM--)
	{
		scanf("%d%d", &nLeft, &nRight);
		nTemp = Query(psTree, 1, nLeft, nRight);
		
		printf("%d\n", nTemp.second);
	}

Exit0:

	return 0;
}