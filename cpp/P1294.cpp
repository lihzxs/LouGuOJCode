/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-17 00:00
//	Comment		:	OJ(P1294)
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

void DFS(int** ppnMat, int* pnFlag, int nSum, 
	int nN, int nStart, int& nMax)
{
	if (nSum > nMax)
		nMax = nSum;


	for (int i = 1; i <= nN; i++)
	{
		if (!pnFlag[i] && ppnMat[nStart][i] != 0)
		{
			pnFlag[i] = 1;
			DFS(ppnMat, pnFlag, nSum + ppnMat[nStart][i],
			 nN, i, nMax);
			pnFlag[i] = 0;
		}
	}
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int**			ppnMat			= NULL;
	int*			pnFlag			= NULL;
	int				nX;
	int				nY;
	int				nW;
	int				nMax			= 0;
	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	

	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nX, &nY, &nW);
		ppnMat[nX][nY] = max(ppnMat[nX][nY], nW);
		ppnMat[nY][nX] = ppnMat[nX][nY];
	}

	for (int i = 1; i <= nInputN; i++)
	{
		memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
		pnFlag[i] = 1;
		DFS(ppnMat, pnFlag, 0,
			nInputN, i, nMax);
	}

	printf("%d", nMax);


Exit0:

	return 0;
}