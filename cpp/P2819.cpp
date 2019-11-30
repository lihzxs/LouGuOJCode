/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-12 16:28
//	Comment		:	OJ(P2819)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


bool Check(int** ppnMat, int* pnColor, int nCount)
{
	for (int i = 1; i < nCount; i++)
	{
		if (ppnMat[i][nCount] && pnColor[i] == pnColor[nCount])
			return false;
	}
	return true;
}


void DFS(int** ppnMat, int* pnColor, int nN, 
	int nM, int nCount, int& nAns)
{
	if (nCount == nN + 1)
	{
		nAns++;
		return;
	}

	for (int i = 1; i <= nM; i++)
	{
		pnColor[nCount] = i;
		if (!Check(ppnMat, pnColor, nCount))
			continue;
		DFS(ppnMat, pnColor, nN,
			nM, nCount + 1, nAns);
	}
}


int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputK;
	int			nInputM;
	int**		ppnMat			= NULL;
	int*		pnColor			= NULL;
	int			nInputX;
	int			nInputY;
	int			nAns			= 0;
	scanf("%d%d%d", &nInputN, &nInputK, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	pnColor = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnColor, 0, (nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 0; i < nInputK; i++)
	{
		scanf("%d%d", &nInputX, &nInputY);
		ppnMat[nInputX][nInputY] = 1;
		ppnMat[nInputY][nInputX] = 1;
	}


	DFS(ppnMat, pnColor, nInputN,
		nInputM, 1, nAns);

	printf("%d", nAns);


Exit0:

	return 0;
}