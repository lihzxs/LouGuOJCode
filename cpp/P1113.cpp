/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-12 22:46
//	Comment		:	OJ(P1113)
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

int main(int argc, char* argv[])
{
	int**				ppnMat				= NULL;
	int					nInputN;
	int*				pnTime				= NULL;
	int*				pnEnter				= NULL;
	int*				pnMax				= NULL;
	int					nStart;
	int					nLong;
	int					nEnd;
	int					nTemp;
	int					nAns				= 0;
	queue<int>			qT;

	scanf("%d", &nInputN);
	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}
	pnTime = (int*)malloc((nInputN + 1) * sizeof(int));
	pnEnter = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnEnter, 0, (nInputN + 1) * sizeof(int));
	pnMax = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnMax, 0, (nInputN + 1) * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nEnd, &nLong);
		pnTime[nEnd] = nLong;
		while (scanf("%d", &nStart))
		{
			if (nStart == 0)
				break;
			ppnMat[nStart][nEnd] = 1;
			pnEnter[nEnd]++;
		}
	}

	for (int i = 1; i <= nInputN; i++)
	{
		if (pnEnter[i] == 0)
		{
			qT.push(i);
			pnMax[i] = pnTime[i];
		}
	}

	while (!qT.empty())
	{
		nTemp = qT.front();
		qT.pop();
		for (int i = 1; i <= nInputN; i++)
		{
			if (ppnMat[nTemp][i])
			{
				pnEnter[i]--;
				if (pnEnter[i] == 0)
					qT.push(i);
				pnMax[i] = max(pnMax[i], pnMax[nTemp] + pnTime[i]);
			}
		}
	}


	for (int i = 1; i <= nInputN; i++)
		nAns = max(nAns, pnMax[i]);

	printf("%d", nAns);

Exit0:

	return 0;
}