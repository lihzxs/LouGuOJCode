/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-26 23:38
//	Comment		:	OJ(P5638)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	long long				nN;
	long long				nK;
	long long*				pnSeq				= NULL;
	long long*				pnSum				= NULL;
	long long				nAns				= 0;
	long long				nSum				= 0;
	scanf("%lld%lld", &nN, &nK);

	pnSeq = (long long*)malloc((nN + 1) * sizeof(long long));
	pnSum = (long long*)malloc((nN + 1) * sizeof(long long));
	memset(pnSeq, 0, (nN + 1) * sizeof(long long));
	memset(pnSum, 0, (nN + 1) * sizeof(long long));

	pnSum[0] = 0;
	for (int i = 1; i < nN; i++)
	{
		scanf("%lld", pnSeq + i);
		pnSum[i] = pnSeq[i] + pnSum[i - 1];
		nAns += pnSeq[i];
	}

	for (int i = 1; i < nN; i++)
	{
		if (i + nK <= nN - 1)
			nSum = max(nSum, pnSum[i + nK - 1] - pnSum[i - 1]);
		else
			nSum = max(nSum, pnSum[nN - 1] - pnSum[nN - nK - 1]);
	}
	printf("%lld", nAns - nSum);





Exit0:
	return 0;
}