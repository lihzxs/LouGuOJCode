/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-25 16:11
//	Comment		:	OJ(P1518)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int	Flag[20][20][4][20][20][4];

void DFS(int** ppnMat, int*** pppnFlagF, int*** pppnFlagC, int** ppnGuide,
	int nNowFX, int nNowFY, int nNowFG, int nNowCX, int nNowCY, int nNowCG, int nCount)
{
	if (nNowCX == nNowFX && nNowFY == nNowCY)
	{
		printf("%d", nCount);
		exit(0);
	}
	if (Flag[nNowFX][nNowFY][nNowFG][nNowCX][nNowCY][nNowCG])
	{
		printf("0");
		exit(0);
	}
	Flag[nNowFX][nNowFY][nNowFG][nNowCX][nNowCY][nNowCG] = 1;

	if (ppnMat[nNowFX + ppnGuide[nNowFG][0]][nNowFY + ppnGuide[nNowFG][1]])
	{
		nNowFG++;
		if (nNowFG == 4)
			nNowFG = 0;
	}
	else
	{
		nNowFX += ppnGuide[nNowFG][0];
		nNowFY += ppnGuide[nNowFG][1];
	}

	if (ppnMat[nNowCX + ppnGuide[nNowCG][0]][nNowCY + ppnGuide[nNowCG][1]])
	{
		nNowCG++;
		if (nNowCG == 4)
			nNowCG = 0;
	}
	else
	{
		nNowCX += ppnGuide[nNowCG][0];
		nNowCY += ppnGuide[nNowCG][1];
	}

	DFS(ppnMat, pppnFlagF, pppnFlagC, ppnGuide,
		nNowFX, nNowFY, nNowFG, nNowCX, nNowCY, nNowCG, nCount + 1);

}

int main(int argc, char* argv[])
{
	int**					ppnGuide		= NULL;
	ppnGuide = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = -1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = 1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;

	int**					ppnMat			= NULL;
	int***					pppnFlagF			= NULL;
	int***					pppnFlagC			= NULL;
	pppnFlagF = (int***)malloc(15 * sizeof(int**));
	pppnFlagC = (int***)malloc(15 * sizeof(int**));
	ppnMat = (int**)malloc(15 * sizeof(int*));
	
	for (int i = 0; i <= 11; i++)
	{
		ppnMat[i] = (int*)malloc(15 * sizeof(int));
		pppnFlagF[i] = (int**)malloc(15 * sizeof(int*));
		pppnFlagC[i] = (int**)malloc(15 * sizeof(int*));
		for (int j = 0; j < 15; j++)
		{
			pppnFlagF[i][j] = (int*)malloc(5 * sizeof(int));
			pppnFlagC[i][j] = (int*)malloc(5 * sizeof(int));
			memset(pppnFlagF[i][j], 0, 5 * sizeof(int));
			memset(pppnFlagC[i][j], 0, 5 * sizeof(int));
		}
	}

	int				nFX;
	int				nFY;
	int				nFG;
	int				nCX;
	int				nCY;
	int				nCG;
	string			szInput;

	for (int i = 0; i <= 11; i++)
		ppnMat[0][i] = 1;
	for (int i = 0; i <= 11; i++)
		ppnMat[i][0] = 1;
	for (int i = 0; i <= 11; i++)
		ppnMat[11][i] = 1;
	for (int i = 0; i <= 11; i++)
		ppnMat[i][11] = 1;

	for (int i = 1; i <= 10; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
		{
			if (szInput[j] == '*')
				ppnMat[i][j + 1] = 1;
			else
			{
				ppnMat[i][j + 1] = 0;
				if (szInput[j] == 'F')
				{
					nFX = i;
					nFY = j + 1;
				}
				if (szInput[j] == 'C')
				{
					nCX = i;
					nCY = j + 1;
				}
			}
		}
	}
	nFG = 0;
	nCG = 0;
	DFS(ppnMat, pppnFlagF, pppnFlagC, ppnGuide,
		nFX, nFY, nFG, nCX, nCY, nCG, 0);


Exit0:
	return 0;
}