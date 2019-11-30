/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-20 23:18
//	Comment		:	OJ(P2385)
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
	int nN, int nM,int** ppnMat, int** ppnFlag,int** ppnGuide)
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

	while (true)
	{
		nQSize = qBFS.size();
		while (nQSize--)
		{
			prTemp = qBFS.front();
			qBFS.pop();
			for (int i = 4; i < 12; i++)
			{
				nNewX = prTemp.first + ppnGuide[i][0];
				nNewY = prTemp.second + ppnGuide[i][1];

				if (nNewX < 1 || nNewX > nN)
					continue;

				if (nNewY < 1 || nNewY > nM)
					continue;
				
				if (nNewX == nEndX && nNewY == nEndY)
					return nCount + 1;
				if (ppnMat[nNewX][nNewY] == 0 || ppnMat[nNewX][nNewY] == 2)
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
	int					nInputM;
	int					nInputN;
	int					nInputM1;
	int					nInputM2;
	int					nStartX;
	int					nStartY;
	int					nEndX;
	int					nEndY;
	int					nTemp;
	int**				ppnMat					= NULL;
	int**				ppnGuide				= NULL;
	int**				ppnFlag					= NULL;

	scanf("%d%d%d%d", &nInputM, &nInputN, &nInputM1, &nInputM2);


	ppnGuide = (int**)malloc(12 * sizeof(int*));

	for (int i = 0; i < 12; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 2; ppnGuide[0][1] = 2;
	ppnGuide[1][0] = 2; ppnGuide[1][1] = -2;
	ppnGuide[2][0] = -2; ppnGuide[2][1] = 2;
	ppnGuide[3][0] = -2; ppnGuide[3][1] = -2;
	ppnGuide[4][0] = -nInputM1; ppnGuide[4][1] = -nInputM2;
	ppnGuide[5][0] = -nInputM1; ppnGuide[5][1] = nInputM2;
	ppnGuide[6][0] = nInputM1; ppnGuide[6][1] = -nInputM2;
	ppnGuide[7][0] = nInputM1; ppnGuide[7][1] = nInputM2;
	ppnGuide[8][0] = -nInputM2; ppnGuide[8][1] = nInputM1;
	ppnGuide[9][0] = -nInputM2; ppnGuide[9][1] = -nInputM1;
	ppnGuide[10][0] = nInputM2; ppnGuide[10][1] = nInputM1;
	ppnGuide[11][0] = nInputM2; ppnGuide[11][1] = -nInputM1;


	ppnMat = (int**)malloc((nInputM + 1) * sizeof(int*));
	ppnFlag = (int**)malloc((nInputM + 1) * sizeof(int*));
	for (int i = 1; i <= nInputM; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		ppnFlag[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputM; i++)
		for (int j = 1; j <= nInputN; j++)
		{
			scanf("%d", &nTemp);
			ppnMat[i][j] = nTemp;
			if (nTemp == 3)
			{
				nStartX = i;
				nStartY = j;
			}
			if (nTemp == 4)
			{
				nEndX = i;
				nEndY = j;
			}
		}///for (int j = 1; j <= nInputN; j++)

	cout << BFS(nStartX, nStartY, nEndX, nEndY,
		nInputM, nInputN, ppnMat, ppnFlag, ppnGuide);


Exit0:
	return 0;
}