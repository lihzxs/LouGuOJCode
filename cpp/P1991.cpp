/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-23 00:22
//	Comment		:	OJ(P1991)
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
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputP;
	double**		ppnMat = NULL;
	double*			pnDis = 0;
	int*			pnFlag = NULL;
	int*			pnX;
	int*			pnY;
	int				nX;
	int				nY;
	int				nW;
	double			nMin;
	int				nPoint = 1;
	int				nSum = 0;

	scanf("%d%d", &nInputP, &nInputN);

	ppnMat = (double**)malloc((nInputN + 1) * sizeof(double*));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	pnX = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnX, 0, (nInputN + 1) * sizeof(int));
	pnY = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnY, 0, (nInputN + 1) * sizeof(int));
	pnDis = (double*)malloc((nInputN + 1) * sizeof(double));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (double*)malloc((nInputN + 1) * sizeof(double));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(double));
	}
	pnDis[0] = 2000000000;
	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d%d", pnX + i, pnY + i);
		pnDis[i] = 2000000000;
	}

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputN; j++)
		{
			ppnMat[i][j] = sqrt((pnX[i] - pnX[j]) * 1.0 * (pnX[i] - pnX[j]) +
				(pnY[i] - pnY[j]) * 1.0 * (pnY[i] - pnY[j]));
		}
	}


	pnDis[1] = 0;
	for (int i = 1; i <= nInputN; i++)
	{
		nMin = pnDis[0];
		for (int j = 1; j <= nInputN; j++)
		{
			if (pnDis[j] < nMin && pnFlag[j] == false)
			{
				nMin = pnDis[j];
				nPoint = j;
			}
		}

		pnFlag[nPoint] = true;

		for (int j = 1; j <= nInputN; j++)
		{
			if (ppnMat[nPoint][j] != 0)
			{
				if (pnDis[j] > ppnMat[nPoint][j] && pnFlag[j] == false)
					pnDis[j] = ppnMat[nPoint][j];
			}
		}
	}

	sort(pnDis + 1, pnDis + 1 + nInputN);
	printf("%.2f", pnDis[nInputN - nInputP + 1]);

Exit0:

	return 0;
}