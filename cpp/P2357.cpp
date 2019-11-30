
/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-25 00:31
//	Comment		:	OJ(P2357)
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
	long long	nNum;
}SNode;


void BuildTree(SNode* psTree, int nNow, int nLeft,
	int nRight, int* pnSeq)
{
	psTree[nNow].nLazyFlag = 0;
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

	psTree[nNow].nNum = psTree[2 * nNow].nNum +
		psTree[2 * nNow + 1].nNum;
}

void TransFlag(SNode* psTree, int nNow)
{
	if (psTree[nNow].nLazyFlag == 0)
		return;

	psTree[2 * nNow].nNum += psTree[nNow].nLazyFlag *
		(psTree[2 * nNow].nRight - psTree[2 * nNow].nLeft + 1);
	psTree[2 * nNow].nLazyFlag += psTree[nNow].nLazyFlag;
	psTree[2 * nNow + 1].nNum += psTree[nNow].nLazyFlag *
		(psTree[2 * nNow + 1].nRight - psTree[2 * nNow + 1].nLeft + 1);
	psTree[2 * nNow + 1].nLazyFlag += psTree[nNow].nLazyFlag;
	psTree[nNow].nLazyFlag = 0;
}

void Change(SNode* psTree, int nNow, int nLeft,
	int nRight, long long nNum)
{
	if (nLeft <= psTree[nNow].nLeft && psTree[nNow].nRight <= nRight)
	{
		psTree[nNow].nNum += nNum *
			(psTree[nNow].nRight - psTree[nNow].nLeft + 1);
		psTree[nNow].nLazyFlag += nNum;
		return;
	}
	TransFlag(psTree, nNow);

	int		nMid;
	nMid = (psTree[nNow].nLeft + psTree[nNow].nRight) / 2;

	if (nLeft <= nMid)
		Change(psTree, 2 * nNow, nLeft, nRight, nNum);
	if (nRight > nMid)
		Change(psTree, 2 * nNow + 1, nLeft, nRight, nNum);

	psTree[nNow].nNum = psTree[2 * nNow].nNum +
		psTree[2 * nNow + 1].nNum;
}

long long Query(SNode* psTree, int nNow, int nLeft, int nRight)
{
	if (nLeft <= psTree[nNow].nLeft && psTree[nNow].nRight <= nRight)
		return psTree[nNow].nNum;
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

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	psTree = (SNode*)malloc((4 * nInputN + 4) * sizeof(SNode));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	BuildTree(psTree, 1, 1, nInputN, pnSeq);



	while (nInputM--)
	{
		scanf("%d", &nQ);
		if (nQ == 1)
		{
			scanf("%d%d%d", &nLeft, &nRight, &nNum);
			Change(psTree, 1, nLeft, nRight, nNum);
		}
		if (nQ == 2)
		{
			scanf("%d",&nNum);
			Change(psTree, 1, 1, 1, nNum);
		}
		if (nQ == 3)
		{
			scanf("%d", &nNum);
			Change(psTree, 1, 1, 1, -nNum);
		}
		if (nQ == 4)
		{
			scanf("%d%d", &nLeft, &nRight);
			cout << Query(psTree, 1, nLeft, nRight) << endl;
		}
		if (nQ == 5)
		{
			cout << Query(psTree, 1, 1, 1) << endl;
		}
	}


Exit0:

	return 0;
}