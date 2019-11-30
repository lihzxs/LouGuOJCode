/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-14 16:17
//	Comment		:	OJ(P1798)
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
long long		pnSeq[500005];
int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputK;
	int				nInputM;
	int				nS;
	int				nT;

	long long		llMax = -1000000;
	scanf("%d%d%d", &nInputN, &nInputK, &nInputM);

	for (int i = 1; i <= nInputK; i++)
	{
		scanf("%d%d", &nS, &nT);
		if (nT == 0)
			pnSeq[i] = nInputN - nS;
		else
			pnSeq[i] = nS - nInputN;
		llMax = max(llMax, pnSeq[i]);
	}
	nInputN--;
	llMax = (long long)(nInputM) / nInputK * nInputN * 2ll + llMax;
	printf("%lld", llMax);

Exit0:

	return 0;
}