/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-5 22:53
//	Comment		:	OJ(P1934)
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
	int				nInputT;
	long long				nMin;
	int				nAns				= 0;
	int				nIndex;
	long long*			pnSeq				= NULL;
	long long*			pnSum				= NULL;
	long long*			pnAns				= NULL;

	scanf("%d%d", &nInputN, &nInputT);

	pnSeq = (long long*)malloc((nInputN + 1) * sizeof(long long));
	pnSum = (long long*)malloc((nInputN + 1) * sizeof(long long));
	pnAns = (long long*)malloc((nInputN + 1) * sizeof(long long));
	for (int i = 1; i <= nInputN; i++)
		scanf("%lld", pnSeq + i);
	pnSum[0] = 0;
	pnAns[0] = 0;

	for (int i = 1; i <= nInputN; i++)
		pnSum[i] = pnSeq[i] + pnSum[i - 1];

	for (int i = 1; i <= nInputN; i++)
	{
		nMin = pnSeq[i] * nInputN * nInputN + pnAns[i - 1];
		for (int j = 1; j < i; j++)
		{
			if (pnSeq[i] + pnSeq[j] > nInputT)
				continue;
			nMin = min(nMin, (pnSeq[i] + pnSeq[j]) * 
				(pnSum[i] - pnSum[j - 1]) + pnAns[j - 1]);
		}
		pnAns[i] = nMin;
	}

	printf("%lld", pnAns[nInputN]);


Exit0:
	return 0;
}