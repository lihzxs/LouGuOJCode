/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-26 16:24
//	Comment		:	OJ(P1873)
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

bool Check(int* pnSeq, long long llM, int nN, int nH)
{
	long long llSum			= 0;
	for (int i = 0; i < nN; i++)
	{
		if (pnSeq[i] - nH > 0)
			llSum += pnSeq[i] - nH;
		if (llSum >= llM)
			return true;
	}
	return false;
}


int main(int argc, char* argv[])
{
	long long		 nInputN;
	long long		 nInputM;
	int*			 pnSeq				= NULL;
	long long		 llLeft;
	long long		 llRight;
	long long		 llMid;
	int				 nMax				= 0;
	scanf("%lld%lld", &nInputN, &nInputM);
	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &pnSeq[i]);
		nMax = max(nMax, pnSeq[i]);
	}
		

	llLeft = 0;
	llRight = nMax;

	while (llLeft + 1 < llRight)
	{
		llMid = (llLeft + llRight) / 2;
		if (Check(pnSeq, nInputM, nInputN, llMid))
			llLeft = llMid;
		else
			llRight = llMid;
	}

	if (Check(pnSeq, nInputM, nInputN, llLeft))
		printf("%lld", llLeft);
	else
		printf("%lld", llRight);






Exit0:

	return 0;
}