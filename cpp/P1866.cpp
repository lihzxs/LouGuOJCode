/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 21:00
//	Comment		:	OJ(P1866)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>

using namespace std;
#define	MAXNUM		3
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnSeq;
	long long		llAns			= 1;

	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		llAns *= pnSeq[i] - i;
		llAns %= MODNUM;
	}

	printf("%lld", llAns);

Exit0:

	return 0;
}