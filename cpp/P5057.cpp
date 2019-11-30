/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-26 23:45
//	Comment		:	OJ(P5057)
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
	long long	nLazyFlag;
}SNode;


void BuildTree(SNode* psTree, int nNow, int nLeft, int nRight)
{
	psTree[nNow].nLazyFlag = 0;
	psTree[nNow].nLeft = nLeft;
	psTree[nNow].nRight = nRight;

	if (nLeft == nRight)
		return;

	int		nMid;
	nMid = (nLeft + nRight) / 2;

	BuildTree(psTree, 2 * nNow, nLeft, nMid);
	BuildTree(psTree, 2 * nNow + 1, nMid + 1,nRight);

}

void TransFlag(SNode* psTree, int nNow)
{
	if (psTree[nNow].nLazyFlag == 0)
		return;
	psTree[2 * nNow].nLazyFlag += psTree[nNow].nLazyFlag;
	psTree[2 * nNow + 1].nLazyFlag += psTree[nNow].nLazyFlag;
	psTree[nNow].nLazyFlag = 0;
}

void Change(SNode* psTree, int nNow, int nLeft,
	int nRight)
{
	if (nLeft <= psTree[nNow].nLeft && psTree[nNow].nRight <= nRight)
	{
		psTree[nNow].nLazyFlag++;
		return;
	}
	TransFlag(psTree, nNow);

	int		nMid;
	nMid = (psTree[nNow].nLeft + psTree[nNow].nRight) / 2;

	if (nLeft <= nMid)
		Change(psTree, 2 * nNow, nLeft, nRight);
	if (nRight > nMid)
		Change(psTree, 2 * nNow + 1, nLeft, nRight);

}

long long Query(SNode* psTree, int nNow, int nLeft, int nRight)
{
	if (nLeft <= psTree[nNow].nLeft && psTree[nNow].nRight <= nRight)
		return psTree[nNow].nLazyFlag;
	TransFlag(psTree, nNow);

	int			nMid;
	long long	llAns = 0;
	nMid = (psTree[nNow].nLeft + psTree[nNow].nRight) / 2;

	if (nLeft <= nMid)
		llAns += Query(psTree, 2 * nNow, nLeft, nRight);
	if (nRight > nMid)
		llAns += Query(psTree, 2 * nNow + 1, nLeft, nRight);
	return llAns;
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

	psTree = (SNode*)malloc((4 * nInputN + 4) * sizeof(SNode));

	BuildTree(psTree, 1, 1, nInputN);


	while (nInputM--)
	{
		scanf("%d", &nQ);
		if (nQ == 1)
		{
			scanf("%d%d", &nLeft, &nRight);
			Change(psTree, 1, nLeft, nRight);
		}
		else
		{
			scanf("%d", &nNum);
			cout << Query(psTree, 1, nNum, nNum) % 2 << endl;
		}
	}

Exit0:

	return 0;
}