/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-9 22:42
//	Comment		:	OJ(P1257)
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

using namespace std;
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int				nInputN;
	long double			nMin;
	long double			nTemp;
	int*			pnSeqX			= NULL;
	int*			pnSeqY			= NULL;

	scanf("%d", &nInputN);
	pnSeqX = (int*)malloc(nInputN * sizeof(int));
	pnSeqY = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnSeqX + i);
		scanf("%d", pnSeqY + i);
	}
	nMin = (pnSeqX[0] - pnSeqX[1]) * (pnSeqX[0] - pnSeqX[1]) +
		(pnSeqY[0] - pnSeqY[1]) * (pnSeqY[0] - pnSeqY[1]);
	for (int i = 0; i < nInputN; i++)
		for (int j = 0; j < nInputN; j++)
		{
			if (i == j)
				continue;
			nTemp = (pnSeqX[i] - pnSeqX[j]) * (pnSeqX[i] - pnSeqX[j]) * 1.0 +
				(pnSeqY[i] - pnSeqY[j]) * (pnSeqY[i] - pnSeqY[j]) * 1.0;
			if (nMin > nTemp)
				nMin = nTemp;
		}

	printf("%.4Lf", sqrt(nMin));

Exit0:

	return 0;
}