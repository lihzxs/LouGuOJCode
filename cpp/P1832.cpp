/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-8 22:33
//	Comment		:	OJ(P1832)
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
#define	MAXNUM		1005
#define	EPS         0.0001
#define MODNUM		1005


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int PrimeInit(unsigned int* punSeq, BYTE* pbyIsPrime)
{
	int		nIndex = 0;
	memset(pbyIsPrime, true, MAXNUM * sizeof(BYTE));
	pbyIsPrime[0] = false;
	pbyIsPrime[1] = false;//
	for (int i = 2; i < MAXNUM; i++)
	{
		if (pbyIsPrime[i])
		{
			punSeq[nIndex++] = i;
			for (int j = i * 2; j < MAXNUM; j += i)
				pbyIsPrime[j] = 0;
		}
	}
	return nIndex;
}



int main(int argc, char* argv[])
{
	BYTE*				pbyIsPrime			= NULL;
	unsigned int*		punSeq				= NULL;
	unsigned int*		punCount			= NULL;
	long long*			pnBagForm			= NULL;
	int					nInputN;
	int					nTemp;
	int					nIndex = 0;
	int					nCount				= 0;

	scanf("%d", &nInputN);

	pbyIsPrime = (BYTE*)malloc(MAXNUM * sizeof(BYTE));

	punSeq = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));

	punCount = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));

	memset(punCount, 0, MAXNUM * sizeof(unsigned int));

	nIndex = PrimeInit(punSeq, pbyIsPrime);
	pnBagForm = (long long*)malloc((nInputN + 1) * sizeof(long long));
	memset(pnBagForm, 0, (nInputN + 1) * sizeof(long long));
	pnBagForm[0] = 1L;

	for (int i = 0; i < nIndex && punSeq[i] <= nInputN; i++)
		for (int j = punSeq[i]; j <= nInputN; j++)
			pnBagForm[j] += pnBagForm[j - punSeq[i]];


	printf("%lld", pnBagForm[nInputN]);




Exit0:

	return 0;
}