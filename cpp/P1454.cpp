/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-18 22:36
//	Comment		:	OJ(P1454)
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


void DFS(int** ppnMat, int** ppnGuide, int nN, int nM, int nX, int nY)
{
	ppnMat[nX][nY] = 0;

	int nNewX;
	int nNewY;

	for (int i = 0; i < 12; i++)
	{
		nNewX = nX + ppnGuide[i][0];
		nNewY = nY + ppnGuide[i][1];
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
	int					nInputN;
	int					nInputM;
	int**				ppnMat					 = NULL;
	int**				ppnGuide				 = NULL;
	string				szInput;
	int					nAns					 = 0;

	ppnGuide = (int**)malloc(12 * sizeof(int*));
	for (int i = 0; i < 12; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;
	ppnGuide[4][0] = 1; ppnGuide[4][1] = 1;
	ppnGuide[5][0] = -1; ppnGuide[5][1] = -1;
	ppnGuide[6][0] = -1; ppnGuide[6][1] = 1;
	ppnGuide[7][0] = 1; ppnGuide[7][1] = -1;
	ppnGuide[8][0] = 2; ppnGuide[8][1] = 0;
	ppnGuide[9][0] = 0; ppnGuide[9][1] = 2;
	ppnGuide[10][0] = -2; ppnGuide[10][1] = 0;
	ppnGuide[11][0] = 0; ppnGuide[11][1] = -2;

	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));


	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
		{
			if (szInput[j] == '#')
				ppnMat[i][j + 1] = 1;
			else
				ppnMat[i][j + 1] = 0;
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

	printf("%d", nAns);






Exit0:

	return 0;
}