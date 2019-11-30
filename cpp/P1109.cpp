/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 15:51
//	Comment		:	OJ(P1109)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int PrimeInit(unsigned int* punSeq, BYTE* pbyIsPrime)
{
	int		nIndex = 0;
	memset(pbyIsPrime, true, MAXNUM * sizeof(BYTE));
	for (int i = 2; i < MAXNUM; i++)
	{
		if (pbyIsPrime[i])
		{
			punSeq[nIndex++] = i;
			for (int j = i * 2; j < MAXNUM; j += i)
				pbyIsPrime[j] = 0;
		}
	}
	pbyIsPrime[0] = false;
	pbyIsPrime[1] = true;
	return nIndex;
}


int main(int argc, char* argv[])
{
	int					nInputN;
	int*				pnSeq			= NULL;
	int					nInputR;
	int					nInputL;
	int					nCmpRLess				= 0;
	int					nCmpRGreater			= 0;
	int					nCmpLLess				= 0;
	int					nCmpLGreater			= 0;


	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	scanf("%d%d", &nInputL, &nInputR);

	for (int i = 0; i < nInputN; i++)
	{
		if (pnSeq[i] > nInputR)
			nCmpRGreater += pnSeq[i] - nInputR;
		if (pnSeq[i] < nInputR)
			nCmpRLess +=  nInputR - pnSeq[i];

		if (pnSeq[i] > nInputL)
			nCmpLGreater += pnSeq[i] - nInputL;
		if (pnSeq[i] < nInputL)
			nCmpLLess += nInputL - pnSeq[i];
	}

	if (nCmpRGreater > nCmpRLess)
		printf("-1");
	else if (nCmpLLess > nCmpLGreater)
		printf("-1");
	else
		printf("%d", max(nCmpRGreater, nCmpLLess));


Exit0:

	return 0;
}