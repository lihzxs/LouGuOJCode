/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-9 20:50
//	Comment		:	OJ(P1496)
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
#include <list>

using namespace std;
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnSeqL			= NULL;
	int*			pnSeqR			= NULL;
	int*			pnSeqAll		= NULL;
	BOOL*			pbFlag			= NULL;
	int				nCount			= 0;
	int				nAns			= 0;

	scanf("%d", &nInputN);
	pnSeqL = (int*)malloc(nInputN * 2 * sizeof(int));
	pnSeqR = (int*)malloc(nInputN * 2 * sizeof(int));
	pnSeqAll = (int*)malloc(nInputN * 3 * sizeof(int));
	pbFlag = (BOOL*)malloc(nInputN * 3 * sizeof(BOOL));
	memset(pbFlag, 0, nInputN * 3 * sizeof(BOOL));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnSeqL + i);
		pnSeqAll[nCount++] = pnSeqL[i];
		scanf("%d", pnSeqR + i);
		pnSeqAll[nCount++] = pnSeqR[i];
	}

	sort(pnSeqAll, pnSeqAll + nCount);



	for (int i = 0; i < nCount; i++)
	{
		pnSeqL[i] = lower_bound(pnSeqAll,
			pnSeqAll + nCount, pnSeqL[i]) - pnSeqAll;
		pnSeqR[i] = lower_bound(pnSeqAll,
			pnSeqAll + nCount, pnSeqR[i]) - pnSeqAll;

		for (int j = pnSeqL[i]; j < pnSeqR[i]; j++)
			pbFlag[j] = true;
	}


	for (int i = 0; i < nCount - 1; i++)
	{
		if (pbFlag[i])
			nAns += pnSeqAll[i + 1] - pnSeqAll[i];
	}

	printf("%d", nAns);



Exit0:

	return 0;
}