/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 21:12
//	Comment		:	OJ(P3817)
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
	int				nInputX;
	long long		nAns = 0;
	int*			pnSeq = NULL;

	scanf("%d%d", &nInputN, &nInputX);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	for (int i = 1; i < nInputN; i++)
	{
		if (pnSeq[i - 1] + pnSeq[i] > nInputX)
		{
			nAns += pnSeq[i - 1] + pnSeq[i] - nInputX;
			if (pnSeq[i] > pnSeq[i - 1] + pnSeq[i] - nInputX)
				pnSeq[i] -= pnSeq[i - 1] + pnSeq[i] - nInputX;
			else
				pnSeq[i] = 0;


		}
	}

	printf("%lld", nAns);





Exit0:

	return 0;
}