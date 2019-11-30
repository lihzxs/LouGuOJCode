/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-25 23:24
//	Comment		:	OJ(P3395)
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

bool BFS(int nN, int* pnSeqX, int* pnSeqY, int** ppnGuide)
{
	queue<pair<int, int> >	qBFS;
	pair<int, int>			prTemp;
	pair<int, int>			prNew;
	int						nQSize;
	int						nCount = 0;
	int						nNewX;
	int						nNewY;
	int**					ppnFlag = NULL;

	ppnFlag = (int**)malloc((nN + 1) * sizeof(int*));

	for (int i = 1; i <= nN; i++)
	{
		ppnFlag[i] = (int*)malloc((nN + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nN + 1) * sizeof(int));
	}

	prTemp.first = 1;
	prTemp.second = 1;
	ppnFlag[1][1] = 1;
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

				if (nNewY < 1 || nNewY > nN)
					continue;

				if (nNewX == nN && nNewY == nN && !ppnFlag[nN][nN])
					return true;

				prNew.first = nNewX;
				prNew.second = nNewY;

				if (!ppnFlag[nNewX][nNewY])
				{
					ppnFlag[nNewX][nNewY] = 1;
					qBFS.push(prNew);
				}
					
			}

		}///while (nQSize--)
		ppnFlag[pnSeqX[nCount]][pnSeqY[nCount]] = 1;
		nCount++;
		if (nCount >= 2 * nN - 2)
			return false;
	}///while (true)
	return false;
}

int main(int argc, char* argv[])
{
	int**					ppnGuide			 = NULL;
	ppnGuide = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;


	int			nInputT;
	int			nInputN;
	int*		pnSeqX			= NULL;
	int*		pnSeqY			= NULL;
	scanf("%d", &nInputT);
	pnSeqX = (int*)malloc(2500 * sizeof(int));
	pnSeqY = (int*)malloc(2500 * sizeof(int));
	while (nInputT--)
	{
		scanf("%d", &nInputN);
		for (int i = 0; i < 2 * nInputN - 2; i++)
			scanf("%d%d", &pnSeqX[i], &pnSeqY[i]);
		if (nInputN == 1)
		{
			printf("Yes\n");
			continue;
		}
		if (BFS(nInputN, pnSeqX, pnSeqY, ppnGuide))
			printf("Yes\n");
		else
			printf("No\n");

	}



Exit0:

	return 0;
}