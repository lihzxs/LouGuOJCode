/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 23:31
//	Comment		:	OJ(P1434)
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
int				nMax	= 0;

int DFS(int** ppnMat, int** ppnAns, int** ppnGuide,
	int nN, int nM, int nNX, int nNY)
{
	if (ppnAns[nNX][nNY])
		return ppnAns[nNX][nNY];
	
	int nAns = 1;
	for (int i = 0; i < 4; i++)
	{
		int nNewX = nNX + ppnGuide[i][0];
		int nNewY = nNY + ppnGuide[i][1];
		if (nNewX < 1 || nNewX > nN)
			continue;
		if (nNewY < 1 || nNewY > nM)
			continue;
		if (ppnMat[nNewX][nNewY] < ppnMat[nNX][nNY])
			nAns = max(nAns, DFS(ppnMat, ppnAns, ppnGuide,
				nN, nM, nNewX, nNewY) + 1);
	}
	ppnAns[nNX][nNY] = nAns;
	nMax = max(nAns, nMax);
	return nAns;
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int**			ppnMat				= NULL;
	int**			ppnAns				= NULL;
	int**			ppnGuide			= NULL;

	ppnGuide = (int**)malloc(3 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 0; ppnGuide[0][1] = -1;
	ppnGuide[1][0] = -1; ppnGuide[1][1] = 0;
	ppnGuide[2][0] = 0; ppnGuide[2][1] = 1;
	ppnGuide[3][0] = 1; ppnGuide[3][1] = 0;
	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppnAns = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		ppnAns[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnAns[i], 0, (nInputM + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
			scanf("%d", &ppnMat[i][j]);

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			DFS(ppnMat, ppnAns, ppnGuide, nInputN, nInputM, i, j);
		}

	printf("%d", nMax);
Exit0:

	return 0;
}