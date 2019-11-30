/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 01:03
//	Comment		:	OJ(P1531)
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

	psTree[nNow].nNum = max(psTree[2 * nNow].nNum ,
		psTree[2 * nNow + 1].nNum);
}



void Change(SNode* psTree, int nNow, int nLeft,
	int nRight, long long nNum)
{
	if (nLeft <= psTree[nNow].nLeft && psTree[nNow].nRight <= nRight)
	{
		psTree[nNow].nNum = nNum;
		return;
	}

	int		nMid;
	nMid = (psTree[nNow].nLeft + psTree[nNow].nRight) / 2;

	if (nLeft <= nMid)
		Change(psTree, 2 * nNow, nLeft, nRight, nNum);
	if (nRight > nMid)
		Change(psTree, 2 * nNow + 1, nLeft, nRight, nNum);

	psTree[nNow].nNum = max(psTree[2 * nNow].nNum,
		psTree[2 * nNow + 1].nNum);
}

long long Query(SNode* psTree, int nNow, int nLeft, int nRight)
{
	if (nLeft <= psTree[nNow].nLeft && psTree[nNow].nRight <= nRight)
		return psTree[nNow].nNum;

	int			nMid;
	long long	llAns = 0;
	nMid = (psTree[nNow].nLeft + psTree[nNow].nRight) / 2;

	if (nLeft <= nMid)
		llAns = max(Query(psTree, 2 * nNow, nLeft, nRight), llAns);
	if (nRight > nMid)
		llAns = max(Query(psTree, 2 * nNow + 1, nLeft, nRight), llAns);
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
	char			szFlag[10];

	scanf("%d%d", &nInputN, &nInputM);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	psTree = (SNode*)malloc((4 * nInputN + 4) * sizeof(SNode));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	BuildTree(psTree, 1, 1, nInputN, pnSeq);


	while (nInputM--)
	{
		scanf("%s", szFlag);

		if (szFlag[0] == 'Q')
		{
			scanf("%d%d", &nLeft, &nRight);
			printf("%lld\n", Query(psTree, 1, nLeft, nRight));
		}
		else
		{
			scanf("%d%d", &nLeft, &nRight);
			if (pnSeq[nLeft] < nRight)
			{
				Change(psTree, 1, nLeft, nLeft, nRight);
				pnSeq[nLeft] = nRight;
			}
				
		}

	}

Exit0:

	return 0;
}