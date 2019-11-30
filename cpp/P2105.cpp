/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-30 22:28
//	Comment		:	OJ(P2105)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>
#include <sstream>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputK;
	int*			pnSeqX				= NULL;
	int*			pnSeqY				= NULL;
	int*			pnFlag				= NULL;
	int*			pnFlagX				= NULL;
	int				nAns				= 0;
	int				nSum;

	scanf("%d%d%d", &nInputN, &nInputM, &nInputK);

	pnSeqX = (int*)malloc(nInputK * sizeof(int));
	pnSeqY = (int*)malloc(nInputK * sizeof(int));
	pnFlag = (int*)malloc((nInputM + 1) * sizeof(int));
	pnFlagX = (int*)malloc((nInputM + 1) * sizeof(int));
	memset(pnFlagX, 0, (nInputN + 1) * sizeof(int));
	for (int i = 0; i < nInputK; i++)
	{
		scanf("%d%d", pnSeqX + i, pnSeqY + i);
		pnFlagX[pnSeqX[i]] = 1;
	}
		

	for (int i = 1; i <= nInputN; i++)
	{
		if (pnFlagX[i])
			continue;
		memset(pnFlag, 0, (nInputM + 1) * sizeof(int));
		nSum = nInputM;
		for (int j = 0; j < nInputK; j++)
		{
			if (pnSeqY[j] + pnSeqX[j] - i >= 1 && pnSeqX[j] + pnSeqY[j] - i <= nInputM)
			{
				if (!pnFlag[pnSeqY[j] + pnSeqX[j] - i])
				{
					pnFlag[pnSeqY[j] + pnSeqX[j] - i] = 1;
					nSum--;
				}
			}
			if (i - pnSeqX[j] + pnSeqY[j] >= 1 && i - pnSeqX[j] + pnSeqY[j] <= nInputM)
			{
				if (!pnFlag[i - pnSeqX[j] + pnSeqY[j]])
				{
					nSum--;
					pnFlag[i - pnSeqX[j] + pnSeqY[j]] = 1;
				}
			}
			if (!pnFlag[pnSeqY[j]])
			{
				nSum--;
				pnFlag[pnSeqY[j]] = 1;
			}
		}
		nAns += nSum;
	}

	printf("%d", nAns);


Exit0:
	return 0;
}