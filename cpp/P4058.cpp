
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-22 20:08
//	Comment		:	OJ(P4058)
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

bool Check(unsigned long long nS, unsigned long long nL, 
	int* pnH, int* pnA, unsigned long long nN, unsigned long long llX)
{
	unsigned long long		nSum = 0;

	for (int i = 0; i < nN; i++)
	{
		if (pnH[i] + pnA[i] * llX >= nL)
			nSum += pnH[i] + pnA[i] * llX;
		if (nSum >= nS)
			return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	unsigned long long 				nInputN;
	unsigned long long				nInputS;
	unsigned long long				nInputL;
	unsigned long long				nTemp;
	int*			pnSeqH				= NULL;
	int*			pnSeqA				= NULL;
	long long		llLeft;
	long long		llRight;
	long long		llMid;


	scanf("%llu%llu%llu", &nInputN, &nInputS, &nInputL);


	pnSeqA = (int*)malloc(nInputN * sizeof(int));
	pnSeqH = (int*)malloc(nInputN * sizeof(int));


	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeqH + i);

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeqA + i);


	llLeft = 0;
	llRight = 100000000000000000ll;

	while (llLeft <= llRight)
	{
		llMid = (llLeft + llRight) / 2;
		if (Check(nInputS, nInputL, pnSeqH, pnSeqA, nInputN, llMid))
			llRight = llMid - 1;
		else
			llLeft = llMid + 1;
	}
	if (Check(nInputS, nInputL, pnSeqH, pnSeqA, nInputN, llLeft))
		printf("%lld", llLeft);
	else
		printf("%lld", llRight);









Exit0:

	return 0;
}