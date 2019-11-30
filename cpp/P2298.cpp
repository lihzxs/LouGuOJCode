/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-31 19:15
//	Comment		:	OJ(P2298)
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



int BFS(int** ppnMat, int nN, int nM, 
	int nStartX, int nStartY, int nEndX, int nEndY)
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
	int**					ppnGuide = NULL;

	ppnFlag = (int**)malloc((nN + 1) * sizeof(int*));

	for (int i = 1; i <= nN; i++)
	{
		ppnFlag[i] = (int*)malloc((nM + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nM + 1) * sizeof(int));
	}

	ppnGuide = (int**)malloc(4 * sizeof(int*));

	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;

	prTemp.first = nStartX;
	prTemp.second = nStartY;
	ppnFlag[nStartX][nStartY] = 1;
	qBFS.push(prTemp);



	while (!qBFS.empty())
	{
		nCount++;
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

				if (ppnMat[nNewX][nNewY] || ppnFlag[nNewX][nNewY])
					continue;

				prNew.first = nNewX;
				prNew.second = nNewY;
				if (nNewX == nEndX && nNewY == nEndY)
					return nCount;
				ppnFlag[nNewX][nNewY] = 1;
				qBFS.push(prNew);
			}

		}///while (nQSize--)

	}///while (true)

	return 0;
}

int main(int argc, char* argv[])
{

	int				nInputN;
	int				nInputM;
	int**			ppnMat			= NULL;
	string			szInput;
	int				nStartX;
	int				nStartY;
	int				nEndX;
	int				nEndY;
	int				nTemp;



	scanf("%d%d", &nInputN, &nInputM);


	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
		{
			if (szInput[j] == '#')
				ppnMat[i][j + 1] = 1;
			else
				ppnMat[i][j + 1] = 0;

			if (szInput[j] == 'd')
			{
				nEndX = i;
				nEndY = j + 1;
			}
			if (szInput[j] == 'm')
			{
				nStartX = i;
				nStartY = j + 1;
			}
		}
	}


	nTemp = BFS(ppnMat, nInputN, nInputM,
		nStartX, nStartY, nEndX, nEndY);

	if (nTemp)
		printf("%d", nTemp);
	else
		printf("No Way!");


Exit0:
	return 0;
}