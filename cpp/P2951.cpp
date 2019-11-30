/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 20:18
//	Comment		:	OJ(P2951)
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
	map<int, vector<pair<int, int> > >		ppnMat;
	int*		pnDis = NULL;
	int*		pnFlag = NULL;
	int			nStart;
	int			nEnd;
	int			nLong;
	int			nMin;
	int			nPoint;
	int			nMax					= 0;
	int			nIndex					= 0;
	int			nCount					= 0;
	scanf("%d%d", &nInputN, &nInputM);


	pnDis = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 0; i <= nInputN; i++)
		pnDis[i] = 2147483647;

	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		ppnMat[nStart].push_back({ nEnd, 1 });
		ppnMat[nEnd].push_back({ nStart, 1 });
	}



	nStart = 1;
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

	for (int i = 1; i <= nInputN; i++)
	{
		if (pnDis[i] > nMax && pnDis[i] != 2147483647)
		{
			nMax = pnDis[i];
			nIndex = i;
		}
	}
	for (int i = 1; i <= nInputN; i++)
	{
		if (pnDis[i] == nMax)
			nCount++;
	}

	printf("%d %d %d\n", nIndex, nMax, nCount);


Exit0:

	return 0;
}