/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-1 18:30
//	Comment		:	OJ(P1605)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int				nInputN;
int				nInputM;

void DFS(BOOL** ppbMat, int nFX, int nFY, 
	int nNowX, int nNowY,int& nCount, int** ppnDir)
{

	//printf("X:%d Y:%d\n", nNowX, nNowY);
	if (nNowX == nFX && nNowY == nFY)
	{
		nCount++;
		return;
	}

	if (nNowX > nInputM || nNowY > nInputN ||
		nNowX < 1 || nNowY < 1)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (nNowX + ppnDir[i][1] > nInputM || nNowY + ppnDir[i][0] > nInputN ||
			nNowX + ppnDir[i][1] < 1 || nNowY + ppnDir[i][0] < 1)
			continue;
		if (!ppbMat[nNowY + ppnDir[i][0]][nNowX + ppnDir[i][1]])
		{
			ppbMat[nNowY + ppnDir[i][0]][nNowX + ppnDir[i][1]] = 1;
			DFS(ppbMat, nFX, nFY, nNowX + ppnDir[i][1],
				nNowY + ppnDir[i][0], nCount, ppnDir);
			ppbMat[nNowY + ppnDir[i][0]][nNowX + ppnDir[i][1]] = 0;
		}
	}


}



int main(int argc, char* argv[])
{
	BOOL**			ppbMat			= NULL;

	int				nInputT;
	int				nSX;
	int				nSY;
	int				nFX;
	int				nFY;
	int				nBadX;
	int				nBadY;
	int				nCount			= 0;
	int**			ppnDir			= NULL;
	ppnDir = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
	{
		ppnDir[i] = (int*)malloc(2 * sizeof(int));
	}

	ppnDir[0][0] = 1; ppnDir[0][1] = 0;
	ppnDir[1][0] = -1; ppnDir[1][1] = 0;
	ppnDir[2][0] = 0; ppnDir[2][1] = 1;
	ppnDir[3][0] = 0; ppnDir[3][1] = -1;


	scanf("%d%d%d", &nInputN, &nInputM, &nInputT);

	ppbMat = (BOOL**)malloc((nInputN + 1) * sizeof(BOOL*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppbMat[i] = (BOOL*)malloc((nInputM + 1) * sizeof(BOOL));
		memset(ppbMat[i], 0, (nInputM + 1) * sizeof(BOOL));
	}

	scanf("%d%d%d%d", &nSX, &nSY, &nFX, &nFY);
	ppbMat[nSY][nSX] = 1;



	for (int i = 0; i < nInputT; i++)
	{
		scanf("%d%d", &nBadX, &nBadY);
		ppbMat[nBadY][nBadX] = 1;
	}

	DFS(ppbMat, nFX, nFY, nSX,
		nSY, nCount, ppnDir);


	printf("%d", nCount);



Exit0:

	return 0;
}