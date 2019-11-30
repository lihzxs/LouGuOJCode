/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-25 21:41
//	Comment		:	OJ(P1027)
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
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

void Get4Point(int& nX1, int& nY1, int& nX2, int& nY2, 
	int& nX3, int& nY3, int& nX4, int& nY4)
{
	int nAB;
	int nAC;
	int nBC;

	nAB = (nX1 - nX2) * (nX1 - nX2) + (nY1 - nY2) * (nY1 - nY2);
	nAC = (nX1 - nX3) * (nX1 - nX3) + (nY1 - nY3) * (nY1 - nY3);
	nBC = (nX2 - nX3) * (nX2 - nX3) + (nY2 - nY3) * (nY2 - nY3);

	if (nAB + nAC == nBC)
	{
		nX4 = nX2 + nX3 - nX1;
		nY4 = nY2 + nY3 - nY1;
	}
	if (nAB + nBC == nAC)
	{
		nX4 = nX1 + nX3 - nX2;
		nY4 = nY1 + nY3 - nY2;
	}
	if (nBC + nAC == nAB)
	{
		nX4 = nX1 + nX2 - nX3;
		nY4 = nY1 + nY2 - nY3;
	}
}


double Dji(int nStart, int nEnd, double** ppfMat, int nSize)
{
	double*				pnDis = NULL;
	int*				pnFlag = NULL;
	int					nS;
	double				fMin;
	double				fAns;
	int					nPoint;
	fAns = 2e63;
	pnDis = (double*)malloc(nSize * sizeof(double));
	pnFlag = (int*)malloc(nSize * sizeof(int));
	for (int i = 0; i < 4; i++)
	{
		nS = (nStart - 1) * 4 + i;
		
		memset(pnFlag, 0, nSize * sizeof(int));
		for (int j = 0; j < nSize; j++)
			pnDis[j] = 2e63;

		pnDis[nS] = 0;

		for (int z = 0; z < nSize; z++)
		{

			fMin = 2e63;
			for (int j = 0; j < nSize; j++)
			{
				if (pnDis[j] < fMin && pnFlag[j] == false)
				{
					fMin = pnDis[j];
					nPoint = j;
				}
			}

			pnFlag[nPoint] = true;

			for (int j = 0; j < nSize; j++)
			{
				if (pnDis[j] > pnDis[nPoint] + ppfMat[nPoint][j] &&
					pnFlag[j] == false)
					pnDis[j] = pnDis[nPoint] + ppfMat[nPoint][j];
			}
		}
		for (int z = 0; z < 4; z++)
			fAns = min(fAns, pnDis[(nEnd - 1) * 4 + z]);
	}

	free(pnFlag);
	free(pnDis);
	return fAns;


}


int main(int argc, char* argv[])
{
	int					nN;
	int					nS;
	int					nAir;
	int					nT;
	int					nA;
	int					nB;
	int					nX1;
	int					nY1;
	int					nX2;
	int					nY2;
	int					nX3;
	int					nY3;
	int					nX4;
	int					nY4;
	vector<int>			vecX;
	vector<int>			vecY;
	int					nTemp;
	double**			ppfMat			= NULL;



	
	ppfMat = (double**)malloc(1000 * sizeof(double*));

	for (int i = 0; i < 1000; i++)
	{
		ppfMat[i] = (double*)malloc(1000 * sizeof(double));
	}

	scanf("%d", &nN);


	while (nN--)
	{
		scanf("%d%d%d%d", &nS, &nAir, &nA, &nB);

		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
				ppfMat[i][j] = 2e63;
		}
		vecX.clear();
		vecY.clear();

		for (int i = 0; i < nS; i++)
		{
			scanf("%d%d%d%d%d%d", &nX1, &nY1, &nX2, &nY2, &nX3, &nY3);
			scanf("%d", &nT);
			Get4Point(nX1, nY1, nX2, nY2,
				nX3, nY3, nX4, nY4);
			nTemp = vecX.size();
			vecX.push_back(nX1);
			vecY.push_back(nY1);
			vecX.push_back(nX2);
			vecY.push_back(nY2);
			vecX.push_back(nX3);
			vecY.push_back(nY3);
			vecX.push_back(nX4);
			vecY.push_back(nY4);

			for (int i = nTemp; i < vecX.size(); i++)
			{
				for (int j = nTemp; j < vecX.size(); j++)
					ppfMat[i][j] = ppfMat[j][i] =
					sqrt((vecX[i] - vecX[j]) * 1.0 * (vecX[i] - vecX[j]) +
					(vecY[i] - vecY[j]) * 1.0 * (vecY[i] - vecY[j])) * nT;
			}

			for (int i = nTemp; i < vecX.size(); i++)
			{
				for (int j = 0; j < nTemp; j++)
					ppfMat[i][j] = ppfMat[j][i] =
					sqrt((vecX[i] - vecX[j]) * 1.0 * (vecX[i] - vecX[j]) +
					(vecY[i] - vecY[j]) * 1.0 * (vecY[i] - vecY[j])) * nAir;
			}
		}
		printf("%.1f", Dji(nA, nB, ppfMat, vecY.size()));
	}




Exit0:

	return 0;
}