/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-20 22:40
//	Comment		:	OJ(P1927)
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
#define	MAXNUM		7010
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnSeqX			= NULL;
	int*			pnSeqY			= NULL;
	double			fMinRSqr		= 1e9;
	double			fMaxRSqr		= 0;
	int				nCount			= 0;

	scanf("%d", &nInputN);

	pnSeqX = (int*)malloc(nInputN * sizeof(int));
	pnSeqY = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", pnSeqX + i, pnSeqY + i);

	for (int i = 0; i < nInputN; i++)
	{
		for (int j = 0; j < nInputN; j++)
		{
			if (i == j)
				continue;

			if (fMaxRSqr < (pnSeqX[i] - pnSeqX[j]) * (pnSeqX[i] - pnSeqX[j])
				+ (pnSeqY[i] - pnSeqY[j]) * (pnSeqY[i] - pnSeqY[j]))
				fMaxRSqr = (pnSeqX[i] - pnSeqX[j]) * (pnSeqX[i] - pnSeqX[j])
				+ (pnSeqY[i] - pnSeqY[j]) * (pnSeqY[i] - pnSeqY[j]);

		}
		if (fMinRSqr > fMaxRSqr)
			fMinRSqr = fMaxRSqr;

		fMaxRSqr = 0;
	}

	printf("%.4f", fMinRSqr * 3.1415926535);






	


Exit0:

	return 0;
}