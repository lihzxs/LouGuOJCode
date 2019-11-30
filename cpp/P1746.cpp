/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-21 13:15
//	Comment		:	OJ(P1746)
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
#define	EPS         0.001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int BFS(int nStartX, int nStartY, int nEndX, int nEndY,
	int nN, int nM, int** ppnMat, int** ppnFlag, int** ppnGuide)
{
	queue<pair<int, int> >	qBFS;
	pair<int, int>			prTemp;
	pair<int, int>			prNew;
	int						nQSize;
	int						nCount = 0;
	int						nNewX;
	int						nNewY;


	prTemp.first = nStartX;
	prTemp.second = nStartY;
	ppnFlag[nStartX][nStartY] = 1;
	qBFS.push(prTemp);

	while (!qBFS.empty())
	{
		nQSize = qBFS.size();
		while (nQSize--)
		{
			prTemp = qBFS.front();
			qBFS.pop();
			for (int i = 0; i < 4; i++)
			{
				nNewX = prTemp.first + ppnGuide[i][0];
				nNewY = prTemp.second + ppnGuide[i][1];

				if (nNewX < 1 || nNewX > nN)
					continue;

				if (nNewY < 1 || nNewY > nM)
					continue;

				if (nNewX == nEndX && nNewY == nEndY)
					return nCount + 1;
				if (ppnMat[nNewX][nNewY] == 1)
					continue;
				prNew.first = nNewX;
				prNew.second = nNewY;

				if (!ppnFlag[nNewX][nNewY])
				{
					ppnFlag[nNewX][nNewY] = 1;
					qBFS.push(prNew);
				}
			}

		}///while (nQSize--)
		nCount++;
	}///while (true)
}

int main(int argc, char* argv[])
{
	int			nInputN;
	int**		ppnMat				 = NULL;
	int**		ppnFlag				 = NULL;
	int			nInputX1;
	int			nInputX2;
	int			nInputY1;
	int			nInputY2;
	int			nTemp;
	int**		ppnGuide			 = NULL;
	string		szTemp;

	ppnGuide = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;

	scanf("%d", &nInputN);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppnFlag = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		ppnFlag[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nInputN + 1) * sizeof(int));
	}
		


	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szTemp;
		for (int j = 0; j < szTemp.length(); j++)
			ppnMat[i][j + 1] = szTemp[j] - '0';
	}
		
	scanf("%d%d%d%d", &nInputX1, &nInputY1, &nInputX2, &nInputY2);

	cout << BFS(nInputX1, nInputY1, nInputX2, nInputY2,
		nInputN, nInputN, ppnMat, ppnFlag, ppnGuide);


Exit0:
	return 0;
}