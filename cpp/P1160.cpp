/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-27 17:18
//	Comment		:	OJ(P1160)
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
#include <list>
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

typedef struct SList
{
	int			nNum;
	SList*		psNext;
}SList;


int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int					nFlag			= 0;
	map<int, int>		mpIndex;
	map<int, SList*>	mpps;
	int*				pnOut			= NULL;
	int					nCount			= 0;
	int					nK;
	int					nP;
	SList*				psListHead		= NULL;
	SList*				psListTemp		= NULL;
	SList*				psListPre		= NULL;
	SList*				psListStore		= NULL;
	scanf("%d", &nInputN);

	psListHead = (SList*)malloc(sizeof(SList));
	psListHead->nNum = 1;
	psListHead->psNext = NULL;
	mpps[1] = psListHead;
	for (int i = 2; i <= nInputN; i++)
	{
		scanf("%d%d", &nK, &nP);
		psListPre = mpps[nK];

		psListTemp = (SList*)malloc(sizeof(SList));
		psListTemp->nNum = i;

		psListStore = psListPre->psNext;
		psListPre->psNext = psListTemp;
		psListTemp->psNext = psListStore;

		mpps[i] = psListTemp;
		if (!nP)
		{
			swap(psListTemp->nNum, psListPre->nNum);
			swap(mpps[i], mpps[nK]);
		}
	}
	pnOut = (int*)malloc(nInputN * sizeof(int));
	nCount = 0;
	


	while (psListHead != NULL)
	{
		pnOut[nCount] = psListHead->nNum;
		mpIndex[psListHead->nNum] = nCount;
		nCount++;
		psListHead = psListHead->psNext;
	}

	scanf("%d", &nInputM);

	while (nInputM--)
	{
		scanf("%d", &nK);
		pnOut[mpIndex[nK]] = 0;
	}

	for (int i = 0; i < nCount; i++)
	{
		if (pnOut[i] == 0)
			continue;
		if (nFlag)
			printf(" ");
		else
			nFlag = 1;
		printf("%d", pnOut[i]);
	}
Exit0:

	return 0;
}