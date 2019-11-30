/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-8 22:02
//	Comment		:	OJ(P2372)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


void DFS(int** ppnMat, int** ppnGuide, BOOL** ppbFlag,int nX, int nY,int nN, int nM, int& nCount)
{
	int				nNewX;
	int				nNewY;
	for (int i = 0; i < 8; i++)
	{
		nNewX = nX + ppnGuide[i][0];
		nNewY = nY + ppnGuide[i][1];
		if ((nNewX < 1 || nNewX > nN))
		{
			if (i < 4)
				nCount++;
			continue;
		}
		else if ((nNewY < 1 || nNewY > nM))
		{
			if (i < 4)
				nCount++;
			continue;
		}
		else if (ppnMat[nNewX][nNewY] == 0)
		{
			if (i < 4)
				nCount++;
		}
		else if (ppnMat[nNewX][nNewY] == 1 && ppbFlag[nNewX][nNewY] == 0)
		{
			ppbFlag[nNewX][nNewY] = 1;
			DFS(ppnMat, ppnGuide, ppbFlag, nNewX, nNewY, nN, nM, nCount);
		}
			
	}
}



int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int			nInputX;
	int			nInputY;
	int**		ppnMat				= NULL;
	int**		ppnGuide			= NULL;
	BOOL**		ppbFlag				= NULL;
	int			nCount				= 0;
	string		szInput;
	ppnGuide = (int**)malloc(8 * sizeof(int*));
	for (int i = 0; i < 8; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));
	
	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = -1; ppnGuide[1][1] = 0;
	ppnGuide[2][0] = 0; ppnGuide[2][1] = 1;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;
	ppnGuide[4][0] = 1; ppnGuide[4][1] = 1;
	ppnGuide[5][0] = -1; ppnGuide[5][1] = -1;
	ppnGuide[6][0] = 1; ppnGuide[6][1] = -1;
	ppnGuide[7][0] = -1; ppnGuide[7][1] = 1;



	scanf("%d%d%d%d", &nInputN, &nInputM, &nInputX, &nInputY);
	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppbFlag = (BOOL**)malloc((nInputN + 1) * sizeof(BOOL*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		ppbFlag[i] = (BOOL*)malloc((nInputM + 1) * sizeof(BOOL));
		memset(ppbFlag[i], 0, (nInputM + 1) * sizeof(BOOL));
	}
		

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
		{
			if (szInput[j] == 'X')
				ppnMat[i][j + 1] = 1;
			else
				ppnMat[i][j + 1] = 0;
		}
	}
	ppbFlag[nInputX][nInputY] = 1;
	DFS(ppnMat, ppnGuide, ppbFlag,nInputX, nInputY, nInputN, nInputM, nCount);

	printf("%d", nCount);
Exit0:

	return 0;
}