/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-20 15:54
//	Comment		:	OJ(P1443)
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

int**				ppnGuide			= NULL;

void BFS(int nStartX, int nStartY, int** ppnCount, int nN, int nM)
{
	queue<pair<int, int> >	qBFS;
	pair<int, int>			prTemp;
	pair<int, int>			prNew;
	int						nQSize;
	int						nCount				= 0;
	int						nNewX;
	int						nNewY;
	int**					ppnFlag				= NULL;

	ppnFlag = (int**)malloc((nN + 1) * sizeof(int*));

	for (int i = 1; i <= nN; i++)
	{
		ppnFlag[i] = (int*)malloc((nM + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nM + 1) * sizeof(int));
	}

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
			for (int i = 4; i < 12; i++)
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
					ppnFlag[nNewX][nNewY] = 1;
					ppnCount[nNewX][nNewY] = nCount + 1;
					qBFS.push(prNew);
				}
			}

		}///while (nQSize--)
		nCount++;
	}///while (true)


}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputX;
	int				nInputY;
	int				nTemp					= -1;
	int**			ppnCount				= NULL;

	ppnGuide = (int**)malloc(12 * sizeof(int*));

	for (int i = 0; i < 12; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 2; ppnGuide[0][1] = 2;
	ppnGuide[1][0] = 2; ppnGuide[1][1] = -2;
	ppnGuide[2][0] = -2; ppnGuide[2][1] = 2;
	ppnGuide[3][0] = -2; ppnGuide[3][1] = -2;
	ppnGuide[4][0] = -1; ppnGuide[4][1] = -2;
	ppnGuide[5][0] = -1; ppnGuide[5][1] = 2;
	ppnGuide[6][0] = 1; ppnGuide[6][1] = -2;
	ppnGuide[7][0] = 1; ppnGuide[7][1] = 2;
	ppnGuide[8][0] = -2; ppnGuide[8][1] = 1;
	ppnGuide[9][0] = -2; ppnGuide[9][1] = -1;
	ppnGuide[10][0] = 2; ppnGuide[10][1] = 1;
	ppnGuide[11][0] = 2; ppnGuide[11][1] = -1;

	scanf("%d%d%d%d", &nInputN, &nInputM, &nInputX, &nInputY);


	ppnCount = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnCount[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnCount[i], 0, (nInputM + 1) * sizeof(int));
	}

	BFS(nInputX, nInputY, ppnCount, nInputN, nInputM);

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputM; j++)
		{
			if (ppnCount[i][j] != 0)
				printf("%-5d", ppnCount[i][j]);
			else
			{
				if (i == nInputX && j == nInputY)
					nTemp = 0;
				else
					nTemp = -1;
				printf("%-5d", nTemp);
			}
		}
			
		printf("\n");
	}
		
Exit0:
	return 0;
}