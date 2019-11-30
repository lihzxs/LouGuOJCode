/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-29 00:29
//	Comment		:	OJ(P2563)
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
#define	MAXNUM		201
#define	EPS         0.0001
#define MODNUM		2e31


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
	BYTE*				pbyIsPrime = NULL;
	unsigned int*		punSeq = NULL;
	unsigned int*		punCount = NULL;
	int					nInputN;
	int					nTemp;
	int					nIndex = 0;

	pbyIsPrime = (BYTE*)malloc(MAXNUM * sizeof(BYTE));

	punSeq = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));

	nIndex = PrimeInit(punSeq, pbyIsPrime);

	punCount = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));

	memset(punCount, 0, MAXNUM * sizeof(unsigned int));
	
	punCount[0] = 1;
	for (int i = 0; i < nIndex; i++)
	{
		for (int j = punSeq[i]; j < MAXNUM; j++)
			punCount[j] += punCount[j - punSeq[i]];
	}
	while (scanf("%d", &nInputN) != EOF)
		printf("%d\n", punCount[nInputN]);


Exit0:

	return 0;
}