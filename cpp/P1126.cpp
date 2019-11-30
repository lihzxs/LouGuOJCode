/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 23:56
//	Comment		:	OJ(P1126)
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


int BFS(int nStartX, int nStartY, int nEndX, int nEndY,
	int nD, int nN, int nM, int** ppnMat, int** ppnGuide)
{
	queue<pair<pair<int, int>, int> >	qBFS;
	pair<pair<int, int>, int> 			prTemp;
	pair<pair<int, int>, int> 			prNew;
	int						nQSize;
	int						nCount = 0;
	int						nNewX;
	int						nNewY;
	int						ppnFlag[55][55][5];

	memset(ppnFlag, 0, 55 * 55 * 5 * sizeof(int));



	prTemp.first.first = nStartX;
	prTemp.first.second = nStartY;
	prTemp.second = nD;
	ppnFlag[nStartX][nStartY][nD] = 1;
	qBFS.push(prTemp);

	while (!qBFS.empty())
	{
		nQSize = qBFS.size();
		nCount++;
		while (nQSize--)
		{
			prTemp = qBFS.front();
			qBFS.pop();
			for (int i = 1; i <= 3; i++)
			{
				nNewX = prTemp.first.first + ppnGuide[prTemp.second][0] * i;
				nNewY = prTemp.first.second + ppnGuide[prTemp.second][1] * i;
				if (nNewX < 1 || nNewX > nN - 1)
					break;
				if (nNewY < 1 || nNewY > nM - 1)
					break;
				if (nNewX == nEndX && nNewY == nEndY)
					return nCount;
				if (ppnMat[nNewX][nNewY])
					break;
				if (ppnFlag[nNewX][nNewY][prTemp.second])
					continue;
				qBFS.push({ {nNewX, nNewY}, prTemp.second });
				ppnFlag[nNewX][nNewY][prTemp.second] = 1;
			}
			nNewX = prTemp.first.first;
			nNewY = prTemp.first.second;
			if (prTemp.second == 0 || prTemp.second == 2)
			{
				if (!ppnFlag[nNewX][nNewY][1])
				{
					qBFS.push({ {nNewX, nNewY}, 1 });
					ppnFlag[nNewX][nNewY][1] = 1;
				}
				if (!ppnFlag[nNewX][nNewY][3])
				{
					qBFS.push({ {nNewX, nNewY}, 3 });
					ppnFlag[nNewX][nNewY][3] = 1;
				}
			}
			if (prTemp.second == 1 || prTemp.second == 3)
			{
				if (!ppnFlag[nNewX][nNewY][0])
				{
					qBFS.push({ {nNewX, nNewY}, 0 });
					ppnFlag[nNewX][nNewY][0] = 1;
				}
				if (!ppnFlag[nNewX][nNewY][2])
				{
					qBFS.push({ {nNewX, nNewY}, 2 });
					ppnFlag[nNewX][nNewY][2] = 1;
				}
			}
		}///while (nQSize--)

	}///while (!qBFS.empty())
	return -1;
}

int main(int argc, char* argv[])
{
	int						nInputN;
	int						nInputM;
	int**					ppnMat				= NULL;
	int						nStartX;
	int						nStartY;
	int						nEndX;
	int						nEndY;
	int						nD;
	int						nTemp;
	int**					ppnGuide = NULL;
	char					szTemp[10];

	ppnGuide = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 0; ppnGuide[0][1] = 1;
	ppnGuide[1][0] = 1; ppnGuide[1][1] = 0;
	ppnGuide[2][0] = 0; ppnGuide[2][1] = -1;
	ppnGuide[3][0] = -1; ppnGuide[3][1] = 0;
	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 0; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputM + 1) * sizeof(int));
	}
		

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			scanf("%d", &nTemp);
			if (nTemp == 0)
				continue;
			ppnMat[i][j] = 1;
			ppnMat[i - 1][j] = 1;
			ppnMat[i][j - 1] = 1;
			ppnMat[i - 1][j - 1] = 1;
		}
		

	scanf("%d%d%d%d", &nStartX, &nStartY, &nEndX, &nEndY);
	scanf("%s", szTemp);

	if (szTemp[0] == 'E')
		nD = 0;
	if (szTemp[0] == 'S')
		nD = 1;
	if (szTemp[0] == 'W')
		nD = 2;
	if (szTemp[0] == 'N')
		nD = 3;
	if (ppnMat[nStartX][nStartY] == 1)
		cout << -1;
	else if (ppnMat[nEndX][nEndY] == 1)
		cout << -1;
	else if (nStartX == nEndX && nStartY == nEndY)
		cout << 0;
	else
		cout << BFS(nStartX, nStartY, nEndX, nEndY,
			nD, nInputN, nInputM, ppnMat, ppnGuide);

Exit0:

	return 0;
}