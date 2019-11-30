/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 20:35
//	Comment		:	OJ(P1649)
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



int BFS(int nStartX, int nStartY, int** ppnMat, int** ppnGuide, int nN, int nEndX, int nEndY)
{

	struct Node
	{
		int nX;
		int nY;
		int nGuide;
		int nCount;
	};
	queue<struct Node>		qBFS;
	struct Node				prTemp;
	struct Node				prNew;
	int						nQSize;
	int						nCount = 0;
	int						nNewX;
	int						nNewY;
	int						nG;
	int***					ppnFlag = NULL;

	ppnFlag = (int***)malloc((nN + 1) * sizeof(int**));

	for (int i = 1; i <= nN; i++)
	{
		ppnFlag[i] = (int**)malloc((nN + 1) * sizeof(int*));
		for (int j = 1; j <= nN; j++)
		{
			ppnFlag[i][j] = (int*)malloc(4 * sizeof(int));
			memset(ppnFlag[i][j], 0, 4 * sizeof(int));
		}
	}

	for (int i = 0; i < 4; i++)
	{
		prTemp.nX = nStartX;
		prTemp.nY = nStartY;
		prTemp.nGuide = i;
		prTemp.nCount = 0;
		ppnFlag[nStartX][nStartY][i] = 1;
		qBFS.push(prTemp);
	}

	while (!qBFS.empty())
	{
		prTemp = qBFS.front();
		qBFS.pop();
		nNewX = prTemp.nX + ppnGuide[prTemp.nGuide][0];
		nNewY = prTemp.nY + ppnGuide[prTemp.nGuide][1];
		if (nNewX == nEndX && nNewY == nEndY)
			return prTemp.nCount;


		if (!(nNewX < 1 || nNewX > nN))
			if (!(nNewY < 1 || nNewY > nN))
				if (!ppnFlag[nNewX][nNewY][prTemp.nGuide])
					if (!(ppnMat[nNewX][nNewY]))
						qBFS.push({ nNewX,nNewY,prTemp.nGuide, prTemp.nCount });

		nG = prTemp.nGuide;
		for (int i = 0; i < 4; i++)
		{
			if (i == nG)
				continue;
			prTemp.nGuide = i;
			if (!ppnFlag[prTemp.nX][prTemp.nY][prTemp.nGuide])
			{
				ppnFlag[prTemp.nX][prTemp.nY][i] = 1;
				prTemp.nCount++;
				qBFS.push(prTemp);
				prTemp.nCount--;
			}
		}

	}///while (!qBFS.empty())
    return -1;
}


int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	int				nInputN;
	int				nInputM;
	int				nInputX;
	int				nInputY;
	int				nStartX;
	int				nStartY;
	int				nEndX;
	int				nEndY;
	int				nTemp = -1;
	int**			ppnMat = NULL;
	char			szTemp[100];
	int**			ppnGuide = NULL;
	ppnGuide = (int**)malloc(4 * sizeof(int*));

	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;


	scanf("%d", &nInputN);


	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputN; i++)
	{

		for (int j = 0; j < nInputN; j++)
		{
			scanf("%s", szTemp);
			if (szTemp[0] == 'x')
				ppnMat[i][j + 1] = 1;
			else
				ppnMat[i][j + 1] = 0;
			if (szTemp[0] == 'A')
			{
				nStartX = i;
				nStartY = j + 1;
			}
			if (szTemp[0] == 'B')
			{
				nEndX = i;
				nEndY = j + 1;
			}
		}
	}

	cout << BFS(nStartX, nStartY, ppnMat, ppnGuide, nInputN, nEndX, nEndY);


Exit0:
	return 0;
}