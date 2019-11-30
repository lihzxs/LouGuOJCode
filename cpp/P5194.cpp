
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-22 22:08
//	Comment		:	OJ(P5194)
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
#include <float.h>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


void DFS(int* pnSeq, int nC, int nN, long long llSum,
	long long* pnSum, long long& llMax, int nPre)
{
	if (llSum > nC)
		return;
	if (nPre >= 0 && llSum + pnSum[nPre] <= llMax)
		return;
	llMax = max(llSum, llMax);

	for (int i = nPre; i >= 0 && pnSeq[i] < nC; i--)
	{
		DFS(pnSeq, nC, nN, llSum + pnSeq[i],
			pnSum, llMax, i - 1);
	}
}


int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputC;
	long long			llMax				= 0;
	int					nCount				= 0;
	int*				pnSeq				= NULL;
	long long*				pnSum				= NULL;

	scanf("%d%d", &nInputN, &nInputC);

	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pnSum = (long long*)malloc(nInputN * sizeof(long long));
	memset(pnSum, 0, nInputN * sizeof(long long));
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnSeq + i);


		if (i == 0)
			pnSum[i] = pnSeq[i];
		else
			pnSum[i] = pnSeq[i] + pnSum[i - 1];

		if (pnSum[i] == nInputC)
		{
			printf("%d", nInputC);
			return 0;
		}
		
		if (pnSeq[i] == nInputC)
		{
			printf("%d", nInputC);
			return 0;
		}
		if (pnSeq[i] > nInputC)
		{
			nInputN = i;
			break;
		}

		
	}
		

	DFS(pnSeq, nInputC, nInputN - 1, 0,
		pnSum, llMax, nInputN - 1);

	printf("%lld", llMax);



Exit0:

	return 0;
}