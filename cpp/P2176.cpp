/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-24 00:40
//	Comment		:	OJ(P2176)
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

int Dij(int nN, int** ppnMat)
{

	int*		pnDis = NULL;
	int*		pnFlag = NULL;
	pnDis = (int*)malloc((nN + 1) * sizeof(int));
	for (int i = 0; i <= nN; i++)
		pnDis[i] = 2147483647;

	pnFlag = (int*)malloc((nN + 1) * sizeof(int));
	memset(pnFlag, 0, (nN + 1) * sizeof(int));
	int nStart = 1;
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

		for (int j = 1; j <= nN; j++)
		{
			if (ppnMat[nIndex][j] == 0)
				continue;
			if (pnDis[j] > pnDis[nIndex] + ppnMat[nIndex][j])
			{
				pnDis[j] = pnDis[nIndex] + ppnMat[nIndex][j];
				if (!pnFlag[j])
					q.push({ pnDis[j], j });
			}
		}

	}
	int nTemp = pnDis[nN];
	free(pnDis);
	free(pnFlag);
	return nTemp;
}

int main(int argc, char* argv[])
{
	int				nN;
	int				nM;
	int*			pnStart = NULL;
	int*			pnEnd = NULL;
	int*			pnLong = NULL;
	int				nMin;
	int				nMax = 0;
	int				nIndex;
	int**			ppnMat;

	scanf("%d%d", &nN, &nM);

	pnStart = (int*)malloc((nM + 1) * sizeof(int));
	pnEnd = (int*)malloc((nM + 1) * sizeof(int));
	pnLong = (int*)malloc((nM + 1) * sizeof(int));
	ppnMat = (int**)malloc((nN + 1) * sizeof(int*));
	
	for (int i = 1; i <= nN; i++)
	{
		ppnMat[i] = (int*)malloc((nN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nN + 1) * sizeof(int));
	}
		

	for (int i = 1; i <= nM; i++)
	{
		scanf("%d%d%d", pnStart + i, pnEnd + i, pnLong + i);
		ppnMat[pnStart[i]][pnEnd[i]] = pnLong[i];
		ppnMat[pnEnd[i]][pnStart[i]] = pnLong[i];
	}

	nMin = Dij(nN, ppnMat);

	for (int i = 1; i <= nM; i++)
	{
		ppnMat[pnStart[i]][pnEnd[i]] = 2 * pnLong[i];
		ppnMat[pnEnd[i]][pnStart[i]] = 2 * pnLong[i];
		nMax = max(nMax, Dij(nN, ppnMat));
		ppnMat[pnStart[i]][pnEnd[i]] = pnLong[i];
		ppnMat[pnEnd[i]][pnStart[i]] = pnLong[i];
	}

	printf("%d", nMax - nMin);




Exit0:
	return 0;
}