/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-23 23:10
//	Comment		:	OJ(P1265)
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
	double**		ppnMat = NULL;
	double*			pfDis = 0;
	int*			pnFlag = NULL;
	int*			pnX;
	int*			pnY;
	int				nW;
	double			nMin;
	int				nPoint = 1;
	double			nSum = 0;
	double			fTemp;
	scanf("%d", &nInputN);
	pnX = (int*)malloc((nInputN + 1) * sizeof(int));
	pnY = (int*)malloc((nInputN + 1) * sizeof(int));
	//ppnMat = (double**)malloc((nInputN + 1) * sizeof(double*));
	
	


	for (int i = 1; i <= nInputN; i++)
	{
		///ppnMat[i] = (double*)malloc((nInputN + 1) * sizeof(double));
		//memset(ppnMat[i], 0, (nInputN + 1) * sizeof(double));
		scanf("%d%d", pnX + i, pnY + i);
	}

	//for (int i = 1; i <= nInputN; i++)
	//	for (int j = 1; j <= nInputN; j++)
	//		ppnMat[i][j] = sqrt((pnX[i] - pnX[j]) * 1.0 * (pnX[i] - pnX[j]) +
	//		(pnY[i] - pnY[j]) * 1.0 * (pnY[i] - pnY[j]));


	pfDis = (double*)malloc((nInputN + 1) * sizeof(double));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	for (int i = 0; i <= nInputN; i++)
		pfDis[i] = 2000000000;
	pfDis[1] = 0;

	for (int i = 1; i <= nInputN; i++)
	{
		nMin = pfDis[0];
		for (int j = 1; j <= nInputN; j++)
		{
			if (pfDis[j] < nMin && pnFlag[j] == false)
			{
				nMin = pfDis[j];
				nPoint = j;
			}
		}

		pnFlag[nPoint] = true;

		for (int j = 1; j <= nInputN; j++)
		{
			fTemp = sqrt((pnX[nPoint] - pnX[j]) * 1.0 * (pnX[nPoint] - pnX[j]) +
				(pnY[nPoint] - pnY[j]) * 1.0 * (pnY[nPoint] - pnY[j]));
			if (pfDis[j] > fTemp && pnFlag[j] == false)
				pfDis[j] = fTemp;
		}
	}

	for (int i = 1; i <= nInputN; i++)
		nSum += pfDis[i];

	printf("%.2f", nSum);

Exit0:

	return 0;
}