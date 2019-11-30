/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-35 23:35
//	Comment		:	OJ(P1495)
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

long long CalcGCD(long long a, long long b)
{
	if (a%b == 0)
		return b;
	return CalcGCD(b, a%b);
}

long long MinMult(long long nA, long long nB)
{
	return nA * nB / CalcGCD(nA, nB);
}




int main(int argc, char* argv[])
{

	int				nInputN;
	int*			pnSeq				= NULL;
	int*			pnMod				= NULL;
	long long		llTemp;
	long long		llAns;
	scanf("%d", &nInputN);
	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pnMod = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", pnMod + i, pnSeq + i);


	llTemp = pnMod[0];
	llAns = pnSeq[0];

	for (int i = 1; i < nInputN; i++)
	{
		while (llAns % pnMod[i] != pnSeq[i])
			llAns += llTemp;
		llTemp = MinMult(llTemp, pnMod[i]);
	}

	printf("%lld", llAns);


Exit0:

	return 0;
}