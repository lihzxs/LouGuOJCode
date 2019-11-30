/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-28 14:14
//	Comment		:	OJ(P1091)
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

int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnSeq			= NULL;
	int				nMax;
	int				nPre;
	int				nSumCount;
	int				nCount;
	int*			pnCountUp			= NULL;
	int*			pnCountDown			= NULL;
	scanf("%d", &nInputN);
	nMax = 0;

	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pnCountUp = (int*)malloc(nInputN * sizeof(int));
	pnCountDown = (int*)malloc(nInputN * sizeof(int));
	memset(pnCountUp, 0, nInputN * sizeof(int));
	memset(pnCountDown, 0, nInputN * sizeof(int));
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);


	for (int i = 0; i < nInputN; i++)
	{
		pnCountUp[i] = 1;
		for (int j = 0; j < i; j++)
			if (pnSeq[j] < pnSeq[i] && pnCountUp[j] + 1 > pnCountUp[i])
				pnCountUp[i] = pnCountUp[j] + 1;
	}
	for (int i = nInputN - 1; i >= 0; i--)
	{
		pnCountDown[i] = 1;
		for (int j = nInputN - 1; j > i; j--)
			if (pnSeq[j] < pnSeq[i] && pnCountDown[j] + 1 > pnCountDown[i])
				pnCountDown[i] = pnCountDown[j] + 1;
	}


	for (int i = 0; i < nInputN; i++)
		nMax = max(pnCountDown[i] + pnCountUp[i] - 1, nMax);


	printf("%d", nInputN - nMax);



Exit0:

	return 0;
}