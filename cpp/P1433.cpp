/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-13 17:50
//	Comment		:	OJ(P1433)
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

void DFS(double* pnSeqX, double* pnSeqY, int* pnFlag, int nN,
	int nCount, double nPreX, double nPreY,double fSum, double& fMin)
{
	if (fMin < fSum)
		return;
	if (nCount >= nN)
	{
		fMin = min(fMin, fSum);
		return;
	}
	double fTemp;
	for (int i = 0; i < nN; i++)
	{
		if (!pnFlag[i])
		{
			pnFlag[i] = 1;
			fTemp = (nPreX - pnSeqX[i]) * (nPreX - pnSeqX[i]) * 1.0 +
				(nPreY - pnSeqY[i]) * (nPreY - pnSeqY[i]);
			fTemp = sqrt(fTemp);
			DFS(pnSeqX, pnSeqY, pnFlag, nN,
				nCount + 1, pnSeqX[i], pnSeqY[i], fSum + fTemp, fMin);
			pnFlag[i] = 0;
		}
	}
}



int main(int argc, char* argv[])
{
	int				nInputN;
	double*			pnSeqX			= NULL;
	double*			pnSeqY			= NULL;
	int*			pnFlag			= NULL;
	double			fMin			= DBL_MAX;

	scanf("%d", &nInputN);

	pnSeqX = (double*)malloc(nInputN * sizeof(double));
	pnSeqY = (double*)malloc(nInputN * sizeof(double));
	pnFlag = (int*)malloc(nInputN * sizeof(int));
	memset(pnFlag, 0, nInputN * sizeof(int));
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%lf", pnSeqX + i);
		scanf("%lf", pnSeqY + i);
	}

	if (nInputN == 0)
		fMin = 0;
	else
		DFS(pnSeqX, pnSeqY, pnFlag, nInputN,
			0, 0, 0, 0.0, fMin);
	printf("%.2f\n", fMin);




Exit0:

	return 0;
}