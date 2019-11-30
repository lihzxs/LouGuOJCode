/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 00:10
//	Comment		:	OJ(P3406)
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
	int				nInputM;
	long long*			pnSeq				= NULL;
	long long*			pnVal				= NULL;
	long long		llAns				= 0;

	scanf("%d%d", &nInputN, &nInputM);

	pnSeq = (long long*)malloc((nInputM + 1) * sizeof(long long));
	pnVal = (long long*)malloc((nInputN + 1) * sizeof(long long));
	memset(pnVal, 0, (nInputN + 1) * sizeof(long long));

	for (int i = 1; i <= nInputM; i++)
		scanf("%d", pnSeq + i);

	for (int i = 1; i < nInputM; i++)
	{
		int nMax = max(pnSeq[i], pnSeq[i + 1]);
		int nMin = min(pnSeq[i], pnSeq[i + 1]);
		pnVal[nMax]--;
		pnVal[nMin]++;
	}

	for (int i = 1; i <= nInputN; i++)
		pnVal[i] += pnVal[i - 1];

	for (int i = 1; i < nInputN; i++)
	{
		int nA, nB, nC;
		scanf("%d%d%d", &nA, &nB, &nC);
		llAns += min(nA * pnVal[i], nB * pnVal[i] + nC);
	}

	printf("%lld", llAns);



Exit0:

	return 0;
}