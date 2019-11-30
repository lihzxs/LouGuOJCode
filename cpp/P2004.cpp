/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-2 15:14
//	Comment		:	OJ(P2004)
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





int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int			nInputC;
	int			nTemp;
	int			nSum;
	int			nMax				= -1000000000;
	int			nX;
	int			nY;
	int**		ppnMat				= NULL;
	int**		ppnSum				= NULL;

	scanf("%d%d%d", &nInputN, &nInputM, &nInputC);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppnSum = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 0; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		ppnSum[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnSum[i], 0, (nInputM + 1) * sizeof(int));
	}
		


	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			scanf("%d", &nTemp);
			ppnMat[i][j] = nTemp;
		}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
			ppnSum[i][j] = ppnMat[i][j] + ppnSum[i - 1][j]
			+ ppnSum[i][j - 1] - ppnSum[i - 1][j - 1];
	for (int i = 1; i <= nInputN - nInputC + 1; i++)
		for (int j = 1; j <= nInputM - nInputC + 1; j++)
		{
			nSum = ppnSum[i + nInputC - 1][j + nInputC - 1] - ppnSum[i + nInputC - 1][j - 1] -
				ppnSum[i - 1][j + nInputC - 1] + ppnSum[i - 1][j - 1];
			if (nSum > nMax)
			{
				nMax = nSum;
				nX = i;
				nY = j;
			}
		}

	printf("%d %d", nX, nY);


Exit0:

	return 0;
}