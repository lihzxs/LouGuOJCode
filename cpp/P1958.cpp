/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-19 15:29
//	Comment		:	OJ(P1958)
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
#define	MAXNUM		100
#define	EPS         0.0001
#define DirNum		2



typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int g_nCount = 0;

void DFS(int nMaxX, int nMaxY, int nNowX, int nNowY, 
	BYTE** ppbyMat, int** ppnDir)
{
	if (nMaxX == nNowX && nMaxY == nNowY)
	{
		g_nCount++;
		return;
	}
	for (int i = 0; i < DirNum; i++)
	{
		nNowX += ppnDir[i][0];
		nNowY += ppnDir[i][1];
		if (nNowX < 0 || nNowX > nMaxX)
		{
			nNowX -= ppnDir[i][0];
			nNowY -= ppnDir[i][1];
			continue;
		}
		if (nNowY < 0 || nNowY > nMaxY)
		{
			nNowX -= ppnDir[i][0];
			nNowY -= ppnDir[i][1];
			continue;
		}
		if (ppbyMat[nNowY][nNowX])
		{
			nNowX -= ppnDir[i][0];
			nNowY -= ppnDir[i][1];
			continue;
		}
		ppbyMat[nNowY][nNowX] = true;
		DFS(nMaxX, nMaxY, nNowX, nNowY, ppbyMat, ppnDir);
		ppbyMat[nNowY][nNowX] = false;
		nNowX -= ppnDir[i][0];
		nNowY -= ppnDir[i][1];
	}
}




int main(int argc, char* argv[])
{
	int				nInputA;
	int				nInputB;
	int				nInputN;
	int				nInputX;
	int				nInputY;
	BYTE**			ppbyMat;
	int**			ppnDir;

	scanf("%d%d%d", &nInputA, &nInputB, &nInputN);
	// B Y dim
	// A X dim
	ppbyMat = (BYTE**)malloc((nInputB + 1) * sizeof(BYTE*));

	for (int j = 0; j < nInputB + 1; j++)
	{
		ppbyMat[j] = (BYTE*)malloc((nInputA + 1) * sizeof(BYTE));
		memset(ppbyMat[j], false, (nInputA + 1) * sizeof(BYTE));
	}

	ppnDir = (int**)malloc(DirNum * sizeof(int*));
	for (int j = 0; j < DirNum; j++)
		ppnDir[j] = (int*)malloc(2 * sizeof(int));

	ppnDir[0][0] = 1; ppnDir[0][1] = 0;
	ppnDir[1][0] = 0; ppnDir[1][1] = 1;

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nInputX, &nInputY);
		ppbyMat[nInputY][nInputX] = true;
	}

	DFS(nInputA, nInputB, 1, 1, ppbyMat, ppnDir);

	printf("%d", g_nCount);








Exit0:

	return 0;
}