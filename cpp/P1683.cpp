/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-1 22:54
//	Comment		:	OJ(P1683)
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

int				nInputW;
int				nInputH;
int g_Max = 0;

void DFS(BOOL** ppbMat, BOOL** ppbCountMat, int nPreX, int nPreY,
	int nNowX, int nNowY, int nCount, int** ppnDir)
{
	//printf("X:%d Y:%d\n", nNowX, nNowY);
	for (int i = 0; i < 4; i++)
	{
		if (nNowX + ppnDir[i][0] > nInputW || nNowY + ppnDir[i][1] > nInputH ||
			nNowX + ppnDir[i][0] < 1 || nNowY + ppnDir[i][1] < 1)
			continue;
		if (ppbMat[nNowY + ppnDir[i][1]][nNowX + ppnDir[i][0]])
			continue;
		if (!ppbCountMat[nNowY + ppnDir[i][1]][nNowX + ppnDir[i][0]])
		{
			ppbCountMat[nNowY + ppnDir[i][1]][nNowX + ppnDir[i][0]] = 1;
			g_Max++;
			DFS(ppbMat, ppbCountMat, nNowX, nNowY, nNowX + ppnDir[i][0],
				nNowY + ppnDir[i][1], nCount + 1, ppnDir);
			//ppbCountMat[nNowY + ppnDir[i][1]][nNowX + ppnDir[i][0]] = 0;
		}
		/*else
			DFS(ppbMat, ppbCountMat, nNowX, nNowY, nNowX + ppnDir[i][0],
				nNowY + ppnDir[i][1], nCount, ppnDir);*/
		
	}
}




int main(int argc, char* argv[])
{
	//int				nInputW;
	//int				nInputH;
	int				nSX;
	int				nSY;
	int				nCount				= 0;
	string			szInput;
	BOOL**			ppbMat				= NULL;
	BOOL**			ppbCountMat			= NULL;
	int**			ppnDir				= NULL;
	ppnDir = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
	{
		ppnDir[i] = (int*)malloc(2 * sizeof(int));
	}

	ppnDir[0][0] = 1; ppnDir[0][1] = 0;
	ppnDir[1][0] = -1; ppnDir[1][1] = 0;
	ppnDir[2][0] = 0; ppnDir[2][1] = 1;
	ppnDir[3][0] = 0; ppnDir[3][1] = -1;

	scanf("%d%d", &nInputW, &nInputH);

	ppbMat = (BOOL**)malloc((nInputH + 1) * sizeof(BOOL*));
	ppbCountMat = (BOOL**)malloc((nInputH + 1) * sizeof(BOOL*));

	for (int i = 1; i <= nInputH; i++)
	{
		ppbMat[i] = (BOOL*)malloc((nInputW + 1) * sizeof(BOOL));
		ppbCountMat[i] = (BOOL*)malloc((nInputW + 1) * sizeof(BOOL));
		memset(ppbCountMat[i], 0, (nInputW + 1) * sizeof(BOOL));
	}

	for (int i = 1; i <= nInputH; i++)
	{
		cin >> szInput;
		for (int j = 0; j < nInputW; j++)
		{
			if (szInput[j] == '@')
			{
				nSX = j + 1;
				nSY = i;
			}
			if (szInput[j] == '.' || szInput[j] == '@')
				ppbMat[i][j + 1] = 0;
			else
				ppbMat[i][j + 1] = 1;

		}
	}
	ppbCountMat[nSY][nSX] = 1;
	DFS(ppbMat, ppbCountMat, nSX, nSY, nSX,
		nSY, 0, ppnDir);

	printf("%d", g_Max + 1);
Exit0:

	return 0;
}