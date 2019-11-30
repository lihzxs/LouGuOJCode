/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-30 23:48
//	Comment		:	OJ(P1332)
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

int**				ppnGuide = NULL;

void BFS(int** ppnMat, int nN, int nM, 
	int* pnStartX, int* pnStartY, int nA, int nB)
{
	queue<pair<int, int> >	qBFS;
	pair<int, int>			prTemp;
	pair<int, int>			prNew;
	int						nQSize;
	int						nCount = 0;
	int						nNewX;
	int						nNewY;
	int						nSum = 0;
	int**					ppnFlag = NULL;

	ppnFlag = (int**)malloc((nN + 1) * sizeof(int*));

	for (int i = 1; i <= nN; i++)
	{
		ppnFlag[i] = (int*)malloc((nM + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nM + 1) * sizeof(int));
	}

	for (int i = 0; i < nA; i++)
	{
		prTemp.first = pnStartX[i];
		prTemp.second = pnStartY[i];
		ppnFlag[pnStartX[i]][pnStartY[i]] = 1;
		qBFS.push(prTemp);
	}
	

	while (!qBFS.empty())
	{
		nCount++;
		nQSize = qBFS.size();
		while (nQSize--)
		{
			prTemp = qBFS.front();
			qBFS.pop();
			nNewX = prTemp.first;
			nNewY = prTemp.second;
			ppnFlag[nNewX][nNewY] = 1;
			if (ppnMat[nNewX][nNewY] == -1)
				ppnMat[nNewX][nNewY] = 0;
			for (int i = 0; i < 4; i++)
			{
				nNewX = prTemp.first + ppnGuide[i][0];
				nNewY = prTemp.second + ppnGuide[i][1];

				if (nNewX < 1 || nNewX > nN)
					continue;

				if (nNewY < 1 || nNewY > nM)
					continue;

				prNew.first = nNewX;
				prNew.second = nNewY;

				if (!ppnFlag[nNewX][nNewY])
				{
					if (ppnMat[nNewX][nNewY] == -1)
						nSum++;
					ppnFlag[nNewX][nNewY] = 1;
					ppnMat[nNewX][nNewY] = nCount;
					if (nSum == nB)
						return;
					qBFS.push(prNew);
				}
			}

		}///while (nQSize--)
		
	}///while (true)


}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputA;
	int				nInputB;
	int*			pnStartX;
	int*			pnStartY;
	int*			pnAnsX;
	int*			pnAnsY;
	int				nX;
	int				nY;
	int				nTemp = -1;
	int**			ppnMat = NULL;

	ppnGuide = (int**)malloc(12 * sizeof(int*));

	for (int i = 0; i < 12; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;


	scanf("%d%d%d%d", &nInputN, &nInputM, &nInputA, &nInputB);


	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputM + 1) * sizeof(int));
	}


	pnStartX = (int*)malloc(nInputA * sizeof(int));
	pnStartY = (int*)malloc(nInputA * sizeof(int));

	pnAnsX = (int*)malloc(nInputB * sizeof(int));
	pnAnsY = (int*)malloc(nInputB * sizeof(int));
	for (int i = 0; i < nInputA; i++)
		scanf("%d%d", pnStartX + i, pnStartY + i);
		

	for (int i = 0; i < nInputB; i++)
	{
		scanf("%d%d", &nX, &nY);
		pnAnsX[i] = nX;
		pnAnsY[i] = nY;
		ppnMat[nX][nY] = -1;
	}
	BFS(ppnMat, nInputN, nInputM,
		pnStartX, pnStartY, nInputA, nInputB);


	for (int i = 0; i < nInputB; i++)
		printf("%d\n", ppnMat[pnAnsX[i]][pnAnsY[i]]);

Exit0:
	return 0;
}