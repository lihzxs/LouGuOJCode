/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-21 16:13
//	Comment		:	OJ(P2872)
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
#define MODNUM		2e63


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int					nPoint;
	double				nMin;
	double				fSum = 0;
	double*				pnDis = NULL;
	int*				pnFlag = NULL;
	int*				pnX = NULL;
	int*				pnY = NULL;
	double**			ppfDis = NULL;

	scanf("%d%d", &nInputN, &nInputM);

	pnX = (int*)malloc((nInputN + 1) * sizeof(int));
	pnY = (int*)malloc((nInputN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	pnDis = (double*)malloc((nInputN + 1) * sizeof(double));
	for (int i = 0; i <= nInputN; i++)
		pnDis[i] = MODNUM;
	ppfDis = (double**)malloc((nInputN + 1) * sizeof(double*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppfDis[i] = (double*)malloc((nInputN + 1) * sizeof(double));
		for (int j = 0; j <= nInputN; j++)
			ppfDis[i][j] = MODNUM;
	}


	for (int i = 1; i <= nInputN; i++)
		scanf("%d%d", pnX + i, pnY + i);

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
		{
			if (j == i)
				continue;
			ppfDis[i][j] = (double)sqrt(double((pnX[i] - pnX[j]) * 1.0 * (pnX[i] - pnX[j]) +
				(pnY[i] - pnY[j]) * 1.0 * (pnY[i] - pnY[j])));
		}

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", pnX, pnY);
		ppfDis[pnX[0]][pnY[0]] = 0;
		ppfDis[pnY[0]][pnX[0]] = 0;
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
			if (ppfDis[nPoint][j] != MODNUM)
			{
				if (pnDis[j] > ppfDis[nPoint][j] && pnFlag[j] == false)
					pnDis[j] = ppfDis[nPoint][j];
			}
		}
	}

	for (int i = 1; i <= nInputN; i++)
		fSum += pnDis[i];

	printf("%.2f", fSum);


Exit0:

	return 0;
}