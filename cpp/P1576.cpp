/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-12 01:15
//	Comment		:	OJ(P1576)
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
	int			nInputN;
	int			nInputM;
	map<int, vector<pair<int, double> > >		ppnMat;
	double*		pnDis = NULL;
	int*		pnFlag = NULL;
	int			nStart;
	int			nEnd;
	double		fLong;
	int			nMin;
	int			nPoint;
	int			nS;
	int			nE;

	scanf("%d%d", &nInputN, &nInputM);

	pnDis = (double*)malloc((nInputN + 1) * sizeof(double));
	for (int i = 0; i <= nInputN; i++)
		pnDis[i] = -2147483647;

	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%lf", &nStart, &nEnd, &fLong);
		ppnMat[nStart].push_back({ nEnd, 1 - fLong / 100 });
		ppnMat[nEnd].push_back({ nStart, 1 - fLong / 100 });
	}
	scanf("%d%d", &nS, &nE);


	nStart = nS;
	pnDis[nStart] = 1;
	priority_queue<pair<double, int>, vector<pair<double, int> >, less<pair<double, int> > > q;
	q.push({ 1, nStart });

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
			if (pnDis[ppnMat[nIndex][j].first] < pnDis[nIndex] * ppnMat[nIndex][j].second)
			{
				if (!pnFlag[ppnMat[nIndex][j].first])
				{
					pnDis[ppnMat[nIndex][j].first] = pnDis[nIndex] * ppnMat[nIndex][j].second;
					q.push({ pnDis[ppnMat[nIndex][j].first], ppnMat[nIndex][j].first });
				}
			}
		}
	}

	printf("%.8f\n", 100 / pnDis[nE]);
Exit0:

	return 0;
}