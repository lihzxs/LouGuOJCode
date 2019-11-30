/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-26 23:00
//	Comment		:	OJ(P3373)
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

int g_nMode;

typedef struct SNode
{
	int			nLeft;
	int			nRight;
	long long	nLazyAddFlag;
	long long	nLazyMultFlag;
	long long	nNum;
}SNode;


void BuildTree(SNode* psTree, int nNow, int nLeft, 
	int nRight, int* pnSeq)
{
	psTree[nNow].nLazyAddFlag = 0;
	psTree[nNow].nLazyMultFlag = 1;
	psTree[nNow].nLeft = nLeft;
	psTree[nNow].nRight = nRight;
	if (nLeft == nRight)
	{
		psTree[nNow].nNum = pnSeq[nLeft] % g_nMode;
		return ;
	}
	int		nMid;
	nMid = (nLeft + nRight) / 2;

	BuildTree(psTree, 2 * nNow, nLeft,
		nMid, pnSeq);
	BuildTree(psTree, 2 * nNow + 1, nMid + 1,
		nRight, pnSeq);

	psTree[nNow].nNum = (psTree[2 * nNow].nNum + 
		psTree[2 * nNow + 1].nNum) % g_nMode;
}

void TransFlag(SNode* psTree, int nNow)
{
	if (psTree[nNow].nLazyAddFlag == 0 && psTree[nNow].nLazyMultFlag == 1)
		return;
	psTree[2 * nNow].nNum = psTree[2 * nNow].nNum * psTree[nNow].nLazyMultFlag +
		psTree[nNow].nLazyAddFlag * (psTree[2 * nNow].nRight - psTree[2 * nNow].nLeft + 1);
	psTree[2 * nNow].nNum %= g_nMode;

	psTree[2 * nNow + 1].nNum = psTree[2 * nNow + 1].nNum * psTree[nNow].nLazyMultFlag +
		psTree[nNow].nLazyAddFlag * (psTree[2 * nNow + 1].nRight - psTree[2 * nNow + 1].nLeft + 1);
	psTree[2 * nNow + 1].nNum %= g_nMode;

	psTree[2 * nNow].nLazyMultFlag *= psTree[nNow].nLazyMultFlag;
	psTree[2 * nNow].nLazyMultFlag %= g_nMode;

	psTree[2 * nNow + 1].nLazyMultFlag *= psTree[nNow].nLazyMultFlag;
	psTree[2 * nNow + 1].nLazyMultFlag %= g_nMode;

	psTree[2 * nNow].nLazyAddFlag = psTree[2 * nNow].nLazyAddFlag * 
		psTree[nNow].nLazyMultFlag + psTree[nNow].nLazyAddFlag;
	psTree[2 * nNow].nLazyAddFlag %= g_nMode;

	psTree[2 * nNow + 1].nLazyAddFlag = psTree[2 * nNow + 1].nLazyAddFlag *
		psTree[nNow].nLazyMultFlag + psTree[nNow].nLazyAddFlag;
	psTree[2 * nNow + 1].nLazyAddFlag %= g_nMode;
	
	psTree[nNow].nLazyAddFlag = 0;
	psTree[nNow].nLazyMultFlag = 1;

}

void ChangeAdd(SNode* psTree, int nNow, int nLeft, 
	int nRight, long long nNum)
{
	if (nLeft <= psTree[nNow].nLeft && psTree[nNow].nRight <= nRight)
	{
		psTree[nNow].nNum += nNum *
			(psTree[nNow].nRight - psTree[nNow].nLeft + 1) % g_nMode;
		psTree[nNow].nLazyAddFlag += nNum;
		psTree[nNow].nLazyAddFlag %= g_nMode;
		return;
	}
	TransFlag(psTree, nNow);
	int		nMid;
	nMid = (psTree[nNow].nLeft + psTree[nNow].nRight) / 2;

	if (nLeft <= nMid)
		ChangeAdd(psTree, 2 * nNow, nLeft,nRight, nNum);
	if (nRight > nMid)
		ChangeAdd(psTree, 2 * nNow + 1, nLeft, nRight, nNum);

	psTree[nNow].nNum = (psTree[2 * nNow].nNum + 
		psTree[2 * nNow + 1].nNum) % g_nMode;
}

void ChangeMult(SNode* psTree, int nNow, int nLeft,
	int nRight, long long nNum)
{
	if (nLeft <= psTree[nNow].nLeft && psTree[nNow].nRight <= nRight)
	{
		psTree[nNow].nNum = nNum * psTree[nNow].nNum % g_nMode;
		psTree[nNow].nLazyMultFlag *= nNum;
		psTree[nNow].nLazyMultFlag %= g_nMode;
		psTree[nNow].nLazyAddFlag = psTree[nNow].nLazyAddFlag * nNum;
		psTree[nNow].nLazyAddFlag %= g_nMode;
		return;
	}

	TransFlag(psTree, nNow);

	int		nMid;
	nMid = (psTree[nNow].nLeft + psTree[nNow].nRight) / 2;

	if (nLeft <= nMid)
		ChangeMult(psTree, 2 * nNow, nLeft, nRight, nNum);
	if (nRight > nMid)
		ChangeMult(psTree, 2 * nNow + 1, nLeft, nRight, nNum);

	psTree[nNow].nNum = (psTree[2 * nNow].nNum +
		psTree[2 * nNow + 1].nNum) % g_nMode;
}

long long Query(SNode* psTree, int nNow, int nLeft, int nRight)
{
	if (nLeft <= psTree[nNow].nLeft && psTree[nNow].nRight <= nRight)
		return psTree[nNow].nNum % g_nMode;

	TransFlag(psTree, nNow);

	int			nMid;
	long long	llAns = 0;
	nMid = (psTree[nNow].nLeft + psTree[nNow].nRight) / 2;

	if (nLeft <= nMid)
	{
		llAns += Query(psTree, 2 * nNow, nLeft, nRight);
		llAns %= g_nMode;
	}
		
	if (nRight > nMid)
	{
		llAns += Query(psTree, 2 * nNow + 1, nLeft, nRight);
		llAns %= g_nMode;
	}
		
	return llAns % g_nMode;
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nQ;
	int				nLeft;
	int				nRight;
	int				nNum;
	int*			pnSeq			= NULL;
	SNode*			psTree			= NULL;
	scanf("%d%d%d", &nInputN, &nInputM, &g_nMode);

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
			ChangeMult(psTree, 1, nLeft, nRight, nNum);
		}
		else if (nQ == 2)
		{
			scanf("%d%d%d", &nLeft, &nRight, &nNum);
			ChangeAdd(psTree, 1, nLeft, nRight, nNum);
		}
		else
		{
			scanf("%d%d", &nLeft, &nRight);
			cout << Query(psTree, 1, nLeft, nRight) << endl;
		}
	}

Exit0:

	return 0;
}