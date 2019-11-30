/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-8 16:54
//	Comment		:	OJ(P1497)
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





int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputK;
	int				nInputH;
	long long		llAns				= 1;
	int*			pnSeqH				= NULL;

	scanf("%d%d%d", &nInputN, &nInputK, &nInputH);
	pnSeqH = (int*)malloc(nInputH * sizeof(int));

	for (int i = 0; i < nInputH; i++)
		scanf("%d", pnSeqH + i);

	if (nInputK > nInputN)
		printf("0\n");
	else
	{
		for (int i = 0; i < nInputK; i++)
			llAns *= (nInputN - i) * (nInputN - i);

		for (int i = 0; i < nInputH; i++)
			for (int j = 2; j <= pnSeqH[i]; j++)
				llAns /= j;
		printf("%lld", llAns);
	}


Exit0:

	return 0;
}