/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-16 00:23
//	Comment		:	OJ(P1828)
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

void  Dij(vector<pair<int, int> >* ppnMat, int* pnDis,int nN,int nStart)
{
	
	int*		pnFlag = NULL;


	pnFlag = (int*)malloc((nN + 1) * sizeof(int));
	memset(pnFlag, 0, (nN + 1) * sizeof(int));

	pnDis[nStart] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push({ 0, nStart });

	while (!q.empty())
	{
		int nIndex;
		int	nDis;
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
}





int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int			nInputC;
	vector<pair<int, int> >*		ppnMat;
	int*		pnDis = NULL;
	int*		pnCow = NULL;
	int			nStart;
	int			nEnd;
	int			nLong;
	int			nMin;
	int			nPoint;
	int			nSum ;
	int			nAns				= 2000000000;
	scanf("%d%d%d", &nInputC, &nInputN, &nInputM);
	ppnMat = new vector<pair<int, int> >[nInputN + 1];
	pnCow = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputC; i++)
		scanf("%d", pnCow + i);
	pnDis = (int*)malloc((nInputN + 1) * sizeof(int));
	


	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nLong);
		ppnMat[nStart].push_back({ nEnd, nLong });
		ppnMat[nEnd].push_back({ nStart, nLong });
	}

	for (int i = 1; i <= nInputN; i++)
	{
		for (int i = 0; i <= nInputN; i++)
			pnDis[i] = 2147483647;
		nSum = 0;
		Dij(ppnMat, pnDis, nInputN, i);

		for (int i = 1; i <= nInputC; i++)
			nSum += pnDis[pnCow[i]];
		nAns = min(nAns, nSum);
	}

	printf("%d", nAns);

Exit0:

	return 0;
}