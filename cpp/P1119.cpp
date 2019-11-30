/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-26 00:35
//	Comment		:	OJ(P1119)
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
#define	MAXNUM		1000000000
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int					nN;
	int					nM;
	int*				pnTime;
	int					nTemp;
	int					nQ;
	int**				ppnMat;
	int					nStrat;
	int					nEnd;
	int					nLong;
	scanf("%d%d", &nN, &nM);

	pnTime = (int*)malloc((nN + 1) * sizeof(int));

	for (int i = 0; i < nN; i++)
		scanf("%d", pnTime + i);

	ppnMat = (int**)malloc((nN + 1) * sizeof(int*));
	for (int i = 0; i <= nN; i++)
	{
		ppnMat[i] = (int*)malloc((nN + 1) * sizeof(int));
		for (int j = 0; j <= nN; j++)
			ppnMat[i][j] = MAXNUM;
		ppnMat[i][i] = 0;
	}

	for (int i = 0; i < nM; i++)
	{
		scanf("%d%d%d", &nStrat, &nEnd, &nLong);
		ppnMat[nStrat][nEnd] = min(ppnMat[nStrat][nEnd], nLong);
		ppnMat[nEnd][nStrat] = min(ppnMat[nEnd][nStrat], nLong);
	}


	scanf("%d", &nQ);

	nTemp = 0;
	for (int i = 0; i < nQ; i++)
	{
		scanf("%d%d%d", &nStrat, &nEnd, &nLong);
		while (pnTime[nTemp] <= nLong && nTemp < nN)
		{
			int k = nTemp;
			for (int i = 0; i < nN; i++)
				for (int j = 0; j < nN; j++)
					ppnMat[i][j] = min(ppnMat[i][j], ppnMat[i][k] + ppnMat[k][j]);
			nTemp++;
		}
		if (pnTime[nStrat] > nLong || pnTime[nEnd] > nLong)
			printf("-1\n");
		else
		{
			if (ppnMat[nStrat][nEnd] == MAXNUM)
				printf("-1\n");
			else
				printf("%d\n", ppnMat[nStrat][nEnd]);
		}

	}

	



Exit0:

	return 0;
}