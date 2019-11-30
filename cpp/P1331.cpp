/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-7 23:17
//	Comment		:	OJ(P1331)
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

void DFS(int** ppnMat, int** ppnGuide, int nN, int nM, int nNowX, int nNowY)
{
	ppnMat[nNowX][nNowY] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nNewX = nNowX + ppnGuide[i][0];
		int nNewY = nNowY + ppnGuide[i][1];
		if (nNewX < 1 || nNewX > nN)
			continue;
		if (nNewY < 1 || nNewY > nM)
			continue;
		if (ppnMat[nNewX][nNewY])
			DFS(ppnMat, ppnGuide, nN, nM, nNewX, nNewY);
	}
}


int main(int argc, char* argv[])
{
	int								nInputN;
	int								nInputM;
	int**							ppnMat				= NULL;
	string							szTemp;
	int								nCount;
	int**							ppnGuide = NULL;
	int								nAns				= 0;
	ppnGuide = (int**)malloc(4 * sizeof(int*));
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
	{
		cin >> szTemp;
		for (int j = 0; j < nInputM; j++)
		{
			if (szTemp[j] == '.')
				ppnMat[i][j + 1] = 0;
			else
				ppnMat[i][j + 1] = 1;
		}
	}

	for (int i = 1; i < nInputN; i++)
		for (int j = 1; j < nInputM; j++)
		{
			nCount = 0;
			if (ppnMat[i][j])
				nCount++;
			if (ppnMat[i + 1][j])
				nCount++;
			if (ppnMat[i][j + 1])
				nCount++;
			if (ppnMat[i + 1][j + 1])
				nCount++;
			if (nCount == 3)
			{
				printf("Bad placement.");
				return 0;
			}
		}


	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			if (ppnMat[i][j])
			{
				DFS(ppnMat, ppnGuide, nInputN, nInputM, i, j);
				nAns++;
			}
		}

	printf("There are %d ships.", nAns);

Exit0:

	return 0;
}