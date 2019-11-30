/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-14 16:44
//	Comment		:	OJ(P2802)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

void DFS(int** ppnMat, int** ppnFlag, int** ppnGuide,int nLife,
	int nN, int nM, int nX, int nY, int nCount,int& nMin)
{
	
	if (nLife <= 0)
		return;
	if (ppnMat[nX][nY] == 0)
		return;
	if (nCount >= nMin)
		return;
	if (ppnMat[nX][nY] == 3)
	{
		if (nCount < nMin)
			nMin = nCount;
		return;
	}
	if (ppnMat[nX][nY] == 4)
		nLife = 6;
	int nNewX;
	int nNewY;
	for (int i = 0; i < 4; i++)
	{
		nNewX = nX + ppnGuide[i][0];
		nNewY = nY + ppnGuide[i][1];
		if (nNewX < 1 || nNewX > nN)
			continue;
		if (nNewY < 1 || nNewY > nM)
			continue;
		if (!ppnFlag[nNewX][nNewY])
		{
			ppnFlag[nNewX][nNewY] = 1;
			DFS(ppnMat, ppnFlag, ppnGuide, nLife - 1,
				nN, nM, nNewX, nNewY, nCount + 1, nMin);
			ppnFlag[nNewX][nNewY] = 0;
		}

	}
}

int main(int argc, char* argv[])
{
	int**						ppnGuide			 = NULL;
	int							nInputN;
	int							nInputM;
	int**						ppnMat				 = NULL;
	int**						ppnFlag				 = NULL;
	string						szInput;
	int							nMin;
	int							nStartX;
	int							nStartY;
	int							nTemp;
	ppnGuide = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;

	scanf("%d%d", &nInputN, &nInputM);

	nMin = nInputM * nInputN + 1;
	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppnFlag = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		ppnFlag[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nInputM + 1) * sizeof(int));
	}
		

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputM; j++)
		{
			scanf("%d", &nTemp);
			ppnMat[i][j] = nTemp;
			if (ppnMat[i][j] == 2)
			{
				nStartX = i;
				nStartY = j;
			}
		}
			
	}

	DFS(ppnMat, ppnFlag, ppnGuide, 6,
		nInputN, nInputM, nStartX, nStartY, 0, nMin);
	if (nMin < nInputM * nInputN + 1)
		printf("%d", nMin);
	else
		printf("-1");

Exit0:

	return 0;
}