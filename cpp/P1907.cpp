/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-9 14:05
//	Comment		:	OJ(P1907)
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



int main(int argc, char* argv[])
{
	double							fDirNum;
	double							fRomNum;
	map<int, pair<double, double> >	mpLocal;
	map<int, vector<pair<int, double> > >		ppnMat;
	double							fX;
	double							fY;
	double							fStartX;
	double							fStartY;
	double							fEndX;
	double							fEndY;
	double							fDis;
	int								nStart;
	int								nEnd;
	double*							pnDis = NULL;
	int*							pnFlag = NULL;
	int**							ppnFlag				= NULL;
	double**						ppnDis				= NULL;
	int								nInputN;

	scanf("%lf%lf", &fDirNum, &fRomNum);
	scanf("%d", &nInputN);
	ppnDis = (double**)malloc((nInputN + 4) * sizeof(double*));
	pnDis = (double*)malloc((nInputN + 4) * sizeof(double));
	for (int i = 0; i <= nInputN + 1; i++)
		pnDis[i] = 1000000000;
	ppnFlag = (int**)malloc((nInputN + 4) * sizeof(int*));
	pnFlag = (int*)malloc((nInputN + 4) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 4) * sizeof(int));
	for (int i = 0; i <= nInputN + 1; i++)
	{
		ppnDis[i] = (double*)malloc((nInputN + 4) * sizeof(double));
		ppnFlag[i] = (int*)malloc((nInputN + 4) * sizeof(int));
		memset(ppnFlag[i], 0, (nInputN + 4) * sizeof(int));
		memset(ppnDis[i], 0, (nInputN + 4) * sizeof(double));
	}

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%lf%lf", &fX, &fY);
		mpLocal[i] = {fX, fY};
	}

	nStart = -1;
	nEnd = -1;

	while (nEnd != 0 || nStart != 0)
	{
		scanf("%d%d", &nStart, &nEnd);
		fDis = (mpLocal[nStart].first - mpLocal[nEnd].first) * (mpLocal[nStart].first - mpLocal[nEnd].first) +
			(mpLocal[nStart].second - mpLocal[nEnd].second) * (mpLocal[nStart].second - mpLocal[nEnd].second);
		fDis = sqrt(fDis);
		ppnMat[nStart].push_back({ nEnd, fDis * fRomNum });
		ppnMat[nEnd].push_back({ nStart, fDis * fRomNum });
		ppnFlag[nStart][nEnd] = ppnFlag[nEnd][nStart] = 1;
	}

	
	scanf("%lf%lf", &fStartX, &fStartY);
	mpLocal[0] = { fStartX, fStartY };
	scanf("%lf%lf", &fEndX, &fEndY);
	mpLocal[nInputN + 1] = { fEndX, fEndY };

	for (int i = 0; i <= nInputN + 1; i++)
		for (int j = i + 1; j <= nInputN + 1; j++)
		{
			if (ppnFlag[i][j])
				continue;
			nStart = i;
			nEnd = j;
			fDis = (mpLocal[nStart].first - mpLocal[nEnd].first) * (mpLocal[nStart].first - mpLocal[nEnd].first) +
				(mpLocal[nStart].second - mpLocal[nEnd].second) * (mpLocal[nStart].second - mpLocal[nEnd].second);
			fDis = sqrt(fDis);
			ppnMat[nStart].push_back({ nEnd, fDis * fDirNum });
			ppnMat[nEnd].push_back({ nStart, fDis * fDirNum });
			ppnFlag[nStart][nEnd] = ppnFlag[nEnd][nStart] = 1;
		}
	
	nStart = 0;
	pnDis[nStart] = 0;
	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > q;

	q.push({ 0, nStart });

	while (!q.empty())
	{
		int nIndex;
		double	nDis;
		nDis = q.top().first;
		nIndex = q.top().second;
		q.pop();
		if (pnFlag[nIndex])
			continue;
		pnFlag[nIndex] = 1;

		for (int j = 0; j < ppnMat[nIndex].size(); j++)
		{
			if (pnDis[ppnMat[nIndex][j].first] > pnDis[nIndex] + ppnMat[nIndex][j].second)
			{
				pnDis[ppnMat[nIndex][j].first] = pnDis[nIndex] + ppnMat[nIndex][j].second;
				if (!pnFlag[ppnMat[nIndex][j].first])
					q.push({ pnDis[ppnMat[nIndex][j].first], ppnMat[nIndex][j].first });
			}
		}
	}

	printf("%.4f\n", pnDis[nInputN + 1]);





Exit0:

	return 0;
}