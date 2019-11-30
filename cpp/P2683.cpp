/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-13 00:25
//	Comment		:	OJ(P2683)
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int					nFlag;
	int					nStart;
	int					nEnd;
	int					nLong;
	int**				ppnMat			= NULL;

	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nFlag, &nStart, &nEnd);
		if (nFlag)
		{
			scanf("%d", &nLong);
			nLong++;
			if (ppnMat[nStart][nEnd] == 0)
				ppnMat[nStart][nEnd] = ppnMat[nEnd][nStart] = nLong;
			else
				ppnMat[nStart][nEnd] = ppnMat[nEnd][nStart] = min(nLong, ppnMat[nStart][nEnd]);
			for (int x = 1; x <= nInputN; x++)
				for (int y = 1; y <= nInputN; y++)
				{
					if (x == nStart || y == nStart)
						continue;
					if (!ppnMat[x][nStart])
						continue;
					if (!ppnMat[nStart][y])
						continue;
					if (!ppnMat[x][y])
						ppnMat[x][y] = ppnMat[y][x] = ppnMat[x][nStart] + ppnMat[nStart][y] - 1;
					else
						ppnMat[x][y] = ppnMat[y][x] = min(ppnMat[x][y], ppnMat[x][nStart] + ppnMat[nStart][y] - 1);
				}
			for (int x = 1; x <= nInputN; x++)
				for (int y = 1; y <= nInputN; y++)
				{
					if (x == nEnd || y == nEnd)
						continue;
					if (!ppnMat[x][nEnd])
						continue;
					if (!ppnMat[nEnd][y])
						continue;
					if (!ppnMat[x][y])
						ppnMat[x][y] = ppnMat[y][x] = ppnMat[x][nEnd] + ppnMat[nEnd][y] - 1;
					else
						ppnMat[x][y] = ppnMat[y][x] = min(ppnMat[x][y], ppnMat[x][nEnd] + ppnMat[nEnd][y] - 1);
				}
		}
		else
		{
			if (ppnMat[nStart][nEnd] == 0)
				printf("-1\n");
			else
				printf("%d\n", ppnMat[nStart][nEnd] - 1);
		}
	}



Exit0:

	return 0;
}