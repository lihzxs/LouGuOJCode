/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-27 22:57
//	Comment		:	OJ(P2083)
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

void DFS(pair<int, int>** ppprMat, int** ppnFlag,
	int nX, int nY, int nEndX, int nEndY,int nCount, int& nMin)
{
	if (nCount >= nMin)
		return;
	if (nX == nEndX && nY == nEndY)
		nMin = min(nMin, nCount);

	if (ppnFlag[nX][nY])
		return;

	int				nTemp;
	ppnFlag[nX][nY] = 1;
	nTemp = abs(ppprMat[nX][nY].first - nX);
	DFS(ppprMat, ppnFlag,
		ppprMat[nX][nY].first, ppprMat[nX][nY].second, 
		nEndX, nEndY, nCount + nTemp, nMin);
}



int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int					nInputV;
	int					nEndX;
	int					nEndY;
	int**				ppnFlag				= NULL;
	pair<int, int>**	ppprMat				= NULL;
	int					nMin				= 1000000;
	int					nTemp;

	scanf("%d%d%d", &nInputN, &nInputM, &nInputV);
	scanf("%d%d", &nEndX, &nEndY);
	ppprMat = new pair<int, int>*[nInputN + 1];
	ppnFlag = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnFlag[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nInputM + 1) * sizeof(int));
		ppprMat[i] = new pair<int, int>[nInputM + 1];
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
			scanf("%d%d", &ppprMat[i][j].first, &ppprMat[i][j].second);

	for (int i = 1; i <= nInputM; i++)
	{
		nTemp = ppprMat[1][i].first - 1;
		ppnFlag[1][i] = 1;
		DFS(ppprMat, ppnFlag,
			ppprMat[1][i].first, ppprMat[1][i].second, 
			nEndX, nEndY, 0 + nTemp, nMin);

		for (int i = 1; i <= nInputN; i++)
			memset(ppnFlag[i], 0, (nInputM + 1) * sizeof(int));
	}
	if (nMin == 1000000)
		printf("impossible");
	else
		printf("%d", nMin * nInputV);
		

Exit0:

	return 0;
}