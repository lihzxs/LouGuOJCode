/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-24 1:02
//	Comment		:	OJ(P1395)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int DFS(int nX, int nRoot, vector<pair<int, int> > * ppnMat, int nN, int& nSum, int& nAns)
{
	int nLen = 0;
	int nMax = 0;
	int nTemp;
	for (int i = 0; i < ppnMat[nX].size(); i++)
	{
		if (ppnMat[nX][i].first != nRoot)
		{
			nTemp = DFS(ppnMat[nX][i].first, nX, ppnMat, nN, nSum,nAns);
			nLen += nTemp;
			nMax = max(nMax, nTemp);
		}
	}

	nMax = max(nMax, nN - nLen - 1);

	if (nMax < nSum || (nMax == nSum && nX < nAns))
	{
		nSum = nMax;
		nAns = nX;
	}
	return nLen + 1;

}

int Dij(int nN, int nStart, vector<pair<int, int> > * ppnMat)
{

	int*		pnDis = NULL;
	int*		pnFlag = NULL;
	pnDis = (int*)malloc((nN + 1) * sizeof(int));
	for (int i = 0; i <= nN; i++)
		pnDis[i] = 2147483647;

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
	int nSum = 0;
	for (int i = 1; i <= nN; i++)
		nSum += pnDis[i];
	free(pnDis);
	free(pnFlag);
	return nSum;
}

int main(int argc, char* argv[])
{
	int				nTemp;
	int				nN;
	int				nM;
	int				nStart;
	int				nEnd;
	int				nMin								= 2000000000;
	int				nMax = 0;
	int				nIndex;
	int				nSum = 100000;
	int				nAns = 100000;

	vector<pair<int, int> > *		ppnMat;

	scanf("%d", &nN);

	ppnMat = new vector<pair<int, int> >[nN + 1];
	
	for (int i = 1; i <= nN - 1; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		ppnMat[nStart].push_back({ nEnd, 1 });
		ppnMat[nEnd].push_back({ nStart, 1 });
	}

	DFS(1, 0, ppnMat, nN, nSum, nAns);
	nTemp = Dij(nN, nAns, ppnMat);
	printf("%d %d", nAns, nTemp);

Exit0:
	return 0;
}