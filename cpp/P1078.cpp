/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-23 21:20
//	Comment		:	OJ(P1078)
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
	int					nN;
	int					nK;
	int					nM;
	int					nS;
	int					nT;
	int					nStart;
	int					nEnd;
	int					nLong;
	int*				pnC;
	int**				ppnLimit			= NULL;
	int**				ppnMat				= NULL;

	scanf("%d%d%d%d%d", &nN, &nK, &nM, &nS, &nT);

	pnC = (int*)malloc((nN + 1) * sizeof(int));
	
	for (int i = 1; i <= nN; i++)
		scanf("%d", pnC + i);



	ppnLimit = (int**)malloc((nK + 1) * sizeof(int*));
	ppnMat = (int**)malloc((nN + 1) * sizeof(int*));

	for (int i = 1; i <= nN; i++)
	{
		ppnMat[i] = (int*)malloc((nN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nN + 1) * sizeof(int));
	}

	for (int i = 1; i <= nK; i++)
	{
		ppnLimit[i] = (int*)malloc((nK + 1) * sizeof(int));
		for (int j = 1; j <= nK; j++)
			scanf("%d", &ppnLimit[i][j]);
	}

	for (int i = 0; i < nM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nLong);

		
		if (!ppnLimit[pnC[nEnd]][pnC[nStart]] && pnC[nEnd] != pnC[nStart])
		if (ppnMat[nStart][nEnd] != 0)
			ppnMat[nStart][nEnd] = min(nLong, ppnMat[nStart][nEnd]);
		else
			ppnMat[nStart][nEnd] = nLong;

		if (!ppnLimit[pnC[nStart]][pnC[nEnd]] && pnC[nStart] != pnC[nEnd])
		if (ppnMat[nEnd][nStart] != 0)
			ppnMat[nEnd][nStart] = min(nLong, ppnMat[nEnd][nStart]);
		else
			ppnMat[nEnd][nStart] = nLong;
	}


	for (int k = 1; k <= nN; k++)
		for (int i = 1; i <= nN; i++)
			for (int j = 1; j <= nN; j++)
			{
				if (i == j || i == k || j == k)
					continue;
				if (ppnMat[i][k] == 0)
					continue;
				if (ppnMat[k][j] == 0)
					continue;
				if (ppnMat[i][j] == 0)
					ppnMat[i][j] = ppnMat[i][k] + ppnMat[k][j];
				else
					ppnMat[i][j] = min(ppnMat[i][k] + ppnMat[k][j], ppnMat[i][j]);
			}


	if (ppnMat[nS][nT] == 0 || pnC[nS] == pnC[nT])
		printf("-1");
	else
		printf("%d", ppnMat[nS][nT]);




Exit0:

	return 0;
}