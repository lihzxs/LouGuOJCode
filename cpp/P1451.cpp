/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-9 15:54
//	Comment		:	OJ(P1451)
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

using namespace std;
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

void DFS(int** ppnMat, int** ppnGuide, int nX, int nY, 
	int nNum, int nN, int nM)
{
	ppnMat[nX][nY] = 0;
	int			nNewX;
	int			nNewY;
	for (int i = 0; i < 4; i++)
	{
		nNewX = nX + ppnGuide[i][0];
		nNewY = nY + ppnGuide[i][1];
		if (nNewX < 1 || nNewX > nN)
			continue;
		if (nNewY < 1 || nNewY > nM)
			continue;
		if (ppnMat[nNewX][nNewY])
			DFS(ppnMat, ppnGuide, nNewX, nNewY, nNum, nN, nM);
	}
}



int main(int argc, char* argv[])
{
	int**					ppnGuide				= NULL;
	int**					ppnMat					= NULL;
	int						nInputN;
	int						nInputM;
	int						nAns					= 0;
	string					szInput;
	ppnGuide = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;

	//scanf("%d%d", &nInputN, &nInputM);
	cin >> nInputN >> nInputM;
	ppnMat = (int**)malloc((1500) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		ppnMat[i] = (int*)malloc((1500) * sizeof(int));


	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
			ppnMat[i][j + 1] = szInput[j] - '0';
	}


	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			if (ppnMat[i][j] > 0)
			{
				nAns++;
				DFS(ppnMat, ppnGuide, i, j, ppnMat[i][j], nInputN, nInputM);
			}
		}

	printf("%d", nAns);

Exit0:

	return 0;
}