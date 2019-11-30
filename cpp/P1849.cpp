/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-24 22:23
//	Comment		:	OJ(P1849)
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

int main(int argc, char* argv[])
{
	int					nN;
	int					nStartX;
	int					nStartY;
	int					nX;
	int					nY;
	int**				ppnMat				= NULL;
	int**				ppnFlag				= NULL;
	int**				ppnAns				= NULL;
	int**				ppnGuide			= NULL;

	ppnGuide = (int**)malloc(4 * sizeof(int*));

	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;

	pair<int, int>		prTemp;
	deque<pair<int, int> > qBFS;
	scanf("%d%d%d", &nN, &nStartX, &nStartY);

	ppnMat = (int**)malloc((1000 + 5) * sizeof(int*));
	ppnFlag = (int**)malloc((1000 + 5) * sizeof(int*));
	ppnAns = (int**)malloc((1000 + 5) * sizeof(int*));
	for (int i = 0; i <= 1004; i++)
	{
		ppnMat[i] = (int*)malloc((1000 + 5) * sizeof(int));
		memset(ppnMat[i], 0, (1000 + 5) * sizeof(int));
		ppnFlag[i] = (int*)malloc((1000 + 5) * sizeof(int));
		memset(ppnFlag[i], 0, (1000 + 5) * sizeof(int));
		ppnAns[i] = (int*)malloc((1000 + 5) * sizeof(int));
		memset(ppnAns[i], 0, (1000 + 5) * sizeof(int));
	}
		
	for (int i = 1; i <= nN; i++)
	{
		scanf("%d%d", &nX, &nY);
		ppnMat[nX][nY] = 1;
	}

	qBFS.push_back({ nStartX, nStartY });

	ppnFlag[nStartX][nStartY] = 1;
	ppnAns[nStartX][nStartY] = 0;

	while (!qBFS.empty())
	{
		prTemp = qBFS.front();
		qBFS.pop_front();
		if (prTemp.first == 0 && prTemp.second == 0)
		{
			printf("%d", ppnAns[prTemp.first][prTemp.second]);
			return 0;
		}
		for (int i = 0; i < 4; i++)
		{
			int nNewX = prTemp.first + ppnGuide[i][0];
			int nNewY = prTemp.second + ppnGuide[i][1];
			if (nNewX < 0 || nNewX > 1001)
				continue;
			if (nNewY < 0 || nNewY > 1001)
				continue;
			if (ppnFlag[nNewX][nNewY])
				continue;

			ppnFlag[nNewX][nNewY] = 1;
			ppnAns[nNewX][nNewY] = ppnAns[prTemp.first][prTemp.second] +
				ppnMat[nNewX][nNewY];

			if (ppnMat[nNewX][nNewY])
				qBFS.push_back({ nNewX, nNewY });
			else
				qBFS.push_front({ nNewX, nNewY });

		}
	}




Exit0:
	return 0;
}