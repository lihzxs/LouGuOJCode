/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-16 22:45
//	Comment		:	OJ(P1238)
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
pair<int, int>				prOut[400];
int							nFlag	= 0;
int				nInputN;
int				nInputM;

void DFS(int** ppnMat, int** ppnGuide,int nNowX, int nNowY,
	 int nCount, int& nEndX, int& nEndY)
{
	if (nNowX == nEndX && nNowY == nEndY)
	{
		nFlag = 1;
		for (int i = 0; i < nCount; i++)
			printf("(%d,%d)->", prOut[i].first, prOut[i].second);
		printf("(%d,%d)\n", nNowX, nNowY);
		return;
	}
	prOut[nCount] = { nNowX, nNowY };

	for (int i = 0; i < 4; i++)
	{
		if (nNowX + ppnGuide[i][0] < 1 || nNowX + ppnGuide[i][0] > nInputN)
			continue;
		if (nNowY + ppnGuide[i][1] < 1 || nNowY + ppnGuide[i][1] > nInputM)
			continue;
		if (ppnMat[nNowX + ppnGuide[i][0]][nNowY + ppnGuide[i][1]])
		{
			ppnMat[nNowX + ppnGuide[i][0]][nNowY + ppnGuide[i][1]] = 0;
			DFS(ppnMat, ppnGuide, nNowX + ppnGuide[i][0], nNowY + ppnGuide[i][1],
				nCount + 1, nEndX, nEndY);
			ppnMat[nNowX + ppnGuide[i][0]][nNowY + ppnGuide[i][1]] = 1;
		}
	}
}


int main(int argc, char* argv[])
{

	int				nStartX;
	int				nStartY;
	int				nEndX;
	int				nEndY;
	int**			ppnMat			= NULL;
	int**			ppnGuide = NULL;
	ppnGuide = (int**)malloc(3 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 0; ppnGuide[0][1] = -1;
	ppnGuide[1][0] = -1; ppnGuide[1][1] = 0;
	ppnGuide[2][0] = 0; ppnGuide[2][1] = 1;
	ppnGuide[3][0] = 1; ppnGuide[3][1] = 0;

	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
			scanf("%d", &ppnMat[i][j]);

	scanf("%d%d", &nStartX, &nStartY);
	scanf("%d%d", &nEndX, &nEndY);
    ppnMat[nStartX][nStartY] = 0;
	DFS(ppnMat, ppnGuide, nStartX, nStartY,
		0, nEndX, nEndY);

	if (!nFlag)
		printf("-1");
Exit0:

	return 0;
}