/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-24 23:26
//	Comment		:	OJ(P1875)
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
	int			nN;
	int*		pnSeq				= NULL;
	int*		pnCost				= NULL;
	int*		pnFlag				= NULL;
	int**		ppnMat = NULL;
	int*		pnAns = NULL;
	int			nStart;
	int			nEnd;
	int			nC;
	int			nMin;
	int			nPoint;

	scanf("%d", &nN);
	
	ppnMat = (int**)malloc((nN + 1) * sizeof(int*));
	pnAns = (int*)malloc((nN + 1) * sizeof(int));

	for (int i = 0; i <= nN; i++)
	{
		ppnMat[i] = (int*)malloc((nN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nN + 1) * sizeof(int));
	}

	pnSeq = (int*)malloc((nN + 1) * sizeof(int));
	pnCost = (int*)malloc((nN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nN + 1) * sizeof(int));
	memset(pnFlag, 0, (nN + 1) * sizeof(int));


	for (int i = 0; i < nN; i++)
	{
		scanf("%d", pnCost + i);
		pnAns[i] = 1;
	}
		

	while (scanf("%d%d%d", &nStart, &nEnd, &nC) != EOF)
		ppnMat[nStart][nEnd] = ppnMat[nEnd][nStart] = nC + 1;


	for (int i = 0; i < nN; i++)
	{
		nMin = 2000000000;
		for (int j = 0; j < nN; j++)
			if (!pnFlag[j] && pnCost[j] < nMin)
			{
				nPoint = j;
				nMin = pnCost[j];
			}

		pnFlag[nPoint] = 1;

		for (int j = 0; j < nN; j++)
		{
			if (pnFlag[j] && ppnMat[nPoint][j])
			{
				if (pnCost[nPoint] + pnCost[j] == pnCost[ppnMat[nPoint][j] - 1])
					pnAns[ppnMat[nPoint][j] - 1] += pnAns[nPoint] * pnAns[j];
				if (pnCost[nPoint] + pnCost[j] < pnCost[ppnMat[nPoint][j] - 1])
				{
					pnCost[ppnMat[nPoint][j] - 1] = pnCost[nPoint] + pnCost[j];
					pnAns[ppnMat[nPoint][j] - 1] = pnAns[nPoint] * pnAns[j];
				}
			}

		}

	}

	printf("%d %d", pnCost[0], pnAns[0]);




Exit0:
	return 0;
}