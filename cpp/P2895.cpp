/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 22:27
//	Comment		:	OJ(P2895)
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

void Flag(int** ppnMat, int** ppnGuide,int nX, int nY, int nT)
{
	int nNewX;
	int	nNewY;
	if (ppnMat[nX][nY] == -1)
		ppnMat[nX][nY] = nT;
	else
		ppnMat[nX][nY] = min(ppnMat[nX][nY], nT);

	for (int i = 0; i < 4; i++)
	{
		nNewX = nX + ppnGuide[i][0];
		nNewY = nY + ppnGuide[i][1];
		if (nNewX < 0)
			continue;
		if (nNewY < 0)
			continue;
		if (ppnMat[nNewX][nNewY] == -1)
			ppnMat[nNewX][nNewY] = nT;
		else
			ppnMat[nNewX][nNewY] = min(ppnMat[nNewX][nNewY], nT);
	}
}



int BFS(int nStartX, int nStartY, int** ppnMat, int** ppnGuide)
{
	queue<pair<int, int> >	qBFS;
	pair<int, int>			prTemp;
	pair<int, int>			prNew;
	int						nQSize;
	int						nCount = 0;
	int						nNewX;
	int						nNewY;
	int**					ppnFlag = NULL;

	ppnFlag = (int**)malloc(350 * sizeof(int*));

	for (int i = 0; i < 350; i++)
	{
		ppnFlag[i] = (int*)malloc(350 * sizeof(int));
		memset(ppnFlag[i], 0, 350 * sizeof(int));
	}

	prTemp.first = nStartX;
	prTemp.second = nStartY;
	ppnFlag[nStartX][nStartY] = 1;
	qBFS.push(prTemp);

	while (!qBFS.empty())
	{
		nQSize = qBFS.size();
		nCount++;
		while (nQSize--)
		{
			prTemp = qBFS.front();
			qBFS.pop();
			
			for (int i = 0; i < 4; i++)
			{
				nNewX = prTemp.first + ppnGuide[i][0];
				nNewY = prTemp.second + ppnGuide[i][1];

				if (nNewX < 0)
					continue;

				if (nNewY < 0)
					continue;
				if (ppnFlag[nNewX][nNewY])
					continue;
				if (ppnMat[nNewX][nNewY] == -1)
					return nCount;
				
				if (ppnMat[nNewX][nNewY] - nCount > 0)
				{
					ppnFlag[nNewX][nNewY] = 1;
					prNew.first = nNewX;
					prNew.second = nNewY;
					qBFS.push(prNew);
				}
			}
		}///while (nQSize--)
		
	}///while (!qBFS.empty())
	return -1;
}


int main(int argc, char* argv[])
{
	int						nInputM;
	int**					ppnGuide = NULL;
	int**					ppnMat = NULL;
	int						nX;
	int						nY;
	int						nT;

	ppnGuide = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;

	scanf("%d", &nInputM);

	ppnMat = (int**)malloc(350 * sizeof(int*));

	for (int i = 0; i < 350; i++)
	{
		ppnMat[i] = (int*)malloc(350 * sizeof(int));
		for (int j = 0; j < 350; j++)
			ppnMat[i][j] = -1;
	}

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nX, &nY, &nT);
		Flag(ppnMat, ppnGuide, nX, nY, nT);
	}

		

	

	cout << BFS(0, 0, ppnMat, ppnGuide);




Exit0:

	return 0;
}