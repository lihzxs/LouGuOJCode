/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-20 00:21
//	Comment		:	OJ(P4328)
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

void BFS2(int** ppnCount, int** ppnMat, int** ppnGuide,
	int nR, int nC)
{
	queue<pair<int, int> >	qBFS;
	pair<int, int>			prTemp;
	pair<int, int>			prNew;
	int						nQSize;
	int						nCount = 0;
	int						nNewX;
	int						nNewY;
	int**					ppnFlag = NULL;

	ppnFlag = (int**)malloc((nR + 1) * sizeof(int*));

	for (int i = 1; i <= nR; i++)
	{
		ppnFlag[i] = (int*)malloc((nC + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nC + 1) * sizeof(int));
	}

	for (int i = 1; i <= nR; i++)
		for (int j = 1; j <= nC; j++)
		{
			if (ppnMat[i][j] == 1)
			{
				ppnCount[i][j] = 0;
				prTemp.first = i;
				prTemp.second = j;
				ppnFlag[i][j] = 1;
				qBFS.push(prTemp);
			}
		}




	while (!qBFS.empty())
	{

		prTemp = qBFS.front();
		qBFS.pop();
		for (int i = 0; i < 4; i++)
		{
			nNewX = prTemp.first + ppnGuide[i][0];
			nNewY = prTemp.second + ppnGuide[i][1];

			if (nNewX < 1 || nNewX > nR)
				continue;

			if (nNewY < 1 || nNewY > nC)
				continue;

			if (ppnMat[nNewX][nNewY] == -1)
				continue;
			if (ppnFlag[nNewX][nNewY])
				continue;


			prNew.first = nNewX;
			prNew.second = nNewY;

			ppnFlag[nNewX][nNewY] = 1;

			ppnCount[nNewX][nNewY] =
				ppnCount[prTemp.first][prTemp.second] + 1;

			qBFS.push(prNew);
		}

	}///while (true)
}

int BFS(int** ppnCount, int** ppnMat, int** ppnGuide,
	int nR, int nC, int nStartX, int nStartY, int nEndX, int nEndY)
{
	queue<pair<pair<int, int>, int> >	qBFS;
	pair<pair<int, int>, int>			prTemp;
	pair<pair<int, int>, int>			prNew;
	int						nQSize;
	int						nCount = 0;
	int						nNewX;
	int						nNewY;
	int						nT;
	int**					ppnFlag = NULL;

	ppnFlag = (int**)malloc((nR + 1) * sizeof(int*));

	for (int i = 1; i <= nR; i++)
	{
		ppnFlag[i] = (int*)malloc((nC + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nC + 1) * sizeof(int));
	}

	prTemp.first.first = nStartX;
	prTemp.first.second = nStartY;
	prTemp.second = 0;
	ppnFlag[nStartX][nStartY] = 1;
	qBFS.push(prTemp);

	while (!qBFS.empty())
	{
		prTemp = qBFS.front();
		qBFS.pop();
		for (int i = 0; i < 4; i++)
		{
			nNewX = prTemp.first.first + ppnGuide[i][0];
			nNewY = prTemp.first.second + ppnGuide[i][1];
			nT = prTemp.second + 1;

			if (nNewX < 1 || nNewX > nR)
				continue;

			if (nNewY < 1 || nNewY > nC)
				continue;
			if (nNewX == nEndX && nNewY == nEndY)
				return nT;
			if (ppnMat[nNewX][nNewY] == -1)
				continue;
			if (ppnFlag[nNewX][nNewY])
				continue;

			if (ppnCount[nNewX][nNewY] <= nT)
				continue;
			
			prNew.first.first = nNewX;
			prNew.first.second = nNewY;
			prNew.second = nT;
			ppnFlag[nNewX][nNewY] = 1;
			qBFS.push(prNew);

		}



	}///while (true)

	return -1;

}


int main(int argc, char* argv[])
{
	int**					ppnGuide = NULL;
	int						nInputR;
	int						nInputC;
	int						nStartX;
	int						nStartY;
	int						nEndX;
	int						nEndY;
	int						nTemp;
	int**					ppnMat = NULL;
	int**					ppnCount = NULL;
	int**					ppnFlag = NULL;
	string					szTemp;

	ppnGuide = (int**)malloc(4 * sizeof(int*));

	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;

	scanf("%d%d", &nInputR, &nInputC);

	ppnMat = (int**)malloc((nInputR + 1) * sizeof(int*));
	ppnCount = (int**)malloc((nInputR + 1) * sizeof(int*));

	for (int i = 1; i <= nInputR; i++)
	{
		ppnMat[i] = (int*)malloc((nInputC + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputC + 1) * sizeof(int));
		ppnCount[i] = (int*)malloc((nInputC + 1) * sizeof(int));
		memset(ppnCount[i], 0x3f3f3f, (nInputC + 1) * sizeof(int));

	}

	for (int i = 1; i <= nInputR; i++)
	{
		cin >> szTemp;
		for (int j = 0; j < nInputC; j++)
		{
			if (szTemp[j] == '*')
				ppnMat[i][j + 1] = 1;
			else if (szTemp[j] == 'X')
				ppnMat[i][j + 1] = -1;
			else
				ppnMat[i][j + 1] = 0;

			if (szTemp[j] == 'S')
			{
				nStartX = i;
				nStartY = j + 1;
			}
			if (szTemp[j] == 'D')
			{
				ppnMat[i][j + 1] = -1;
				nEndX = i;
				nEndY = j + 1;
			}
		}
	}


	BFS2(ppnCount, ppnMat, ppnGuide,
		nInputR, nInputC);




	nTemp = BFS(ppnCount, ppnMat, ppnGuide,
		nInputR, nInputC, nStartX, nStartY, nEndX, nEndY);
	if (nTemp == -1)
		printf("KAKTUS");
	else
		printf("%d", nTemp);




Exit0:

	return 0;
}