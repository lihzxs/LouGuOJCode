/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-12 00:22
//	Comment		:	OJ(P3111)
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
	int			nN;
	long long	llT;
	long long	llIndex;
	long long	llSpeed;
	long long*	pllSeq				= NULL;
	int			nAns;
	scanf("%d%lld", &nN, &llT);
	pllSeq = (long long*)malloc(nN * sizeof(long long));
	
	for (int i = 0; i < nN; i++)
	{
		scanf("%lld%lld", &llIndex, &llSpeed);
		pllSeq[i] = llIndex + llSpeed * llT;
	}
	nAns = 1;
	for (int i = nN - 2; i >= 0; i--)
	{
		if (pllSeq[i] >= pllSeq[i + 1])
			pllSeq[i] = pllSeq[i + 1];
		else
			nAns++;
	}

	printf("%d", nAns);

Exit0:

	return 0;
}