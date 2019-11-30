/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-25 00:14
//	Comment		:	OJ(P1522)
//
///////////////////////////////////////////


//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		1e63
#define	EPS         0.0001
#define MODNUM		1e63;


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	int					nN;
	int*				pnX			= NULL;
	int*				pnY			= NULL;
	double*				pfDis		= NULL;
	double**			ppfDis		= NULL;
	string				szTemp;
	int					nTemp;
	double				fTemp;
	double				fMax;
	double				fMin;
	scanf("%d", &nN);

	pnX = (int*)malloc((nN + 1) * sizeof(int));
	pnY = (int*)malloc((nN + 1) * sizeof(int));
	
	pfDis = (double*)malloc((nN + 1) * sizeof(double));
	memset(pfDis, 0, (nN + 1) * sizeof(double));

	ppfDis = (double**)malloc((nN + 1) * sizeof(double*));
	for (int i = 1; i <= nN; i++)
		ppfDis[i] = (double*)malloc((nN + 1) * sizeof(double));


	for (int i = 1; i <= nN; i++)
		scanf("%d%d", pnX + i, pnY + i);


	for (int i = 1; i <= nN; i++)
		for (int j = 1; j <= nN; j++)
		{
			scanf("%1d", &nTemp);
			if (nTemp)
				ppfDis[i][j] = sqrt((pnX[i]- pnX[j]) * 1.0 * (pnX[i] - pnX[j]) + 
				(pnY[i] - pnY[j]) * 1.0 * (pnY[i] - pnY[j]));
			else
				ppfDis[i][j] = MAXNUM;
			ppfDis[i][i] = 0;
		}


	for (int k = 1; k <= nN; k++)
		for (int i = 1; i <= nN; i++)
			for (int j = 1; j <= nN; j++)
				ppfDis[i][j] = min(ppfDis[i][j], 
					ppfDis[i][k] + ppfDis[k][j]);

	fMax = 0;
	for (int i = 1; i <= nN; i++)
		for (int j = 1; j <= nN; j++)
		{
			if (ppfDis[i][j] != MAXNUM)
				pfDis[i] = max(ppfDis[i][j], pfDis[i]);
			fMax = max(pfDis[i], fMax);
		}
	fMin = MAXNUM;
	for (int i = 1; i <= nN; i++)
		for (int j = 1; j <= nN; j++)
		{
			if (ppfDis[i][j] == MAXNUM)
			{
				fTemp = sqrt((pnX[i] - pnX[j]) * 1.0 * (pnX[i] - pnX[j]) +
					(pnY[i] - pnY[j]) * 1.0 * (pnY[i] - pnY[j]));
				fMin = min(pfDis[i] + fTemp + pfDis[j], fMin);
			}
				
		}


	printf("%.6f", max(fMax, fMin));






Exit0:
	return 0;
}