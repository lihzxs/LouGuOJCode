/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-20 20:04
//	Comment		:	OJ(P3416)
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
	int				nInputN;
	int*			pnX			= NULL;
	int*			pnY			= NULL;
	int*			pnDis		= NULL;
	int**			ppnMat		= NULL;
	int				nAns		= 0;
	int				nTemp		= 0;

	scanf("%d", &nInputN);

	pnX = (int*)malloc((nInputN + 1) * sizeof(int));
	pnY = (int*)malloc((nInputN + 1) * sizeof(int));
	pnDis = (int*)malloc((nInputN + 1) * sizeof(int));

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d%d%d", pnX + i, pnY + i, pnDis + i);
		pnDis[i] = pnDis[i] * pnDis[i];
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
			if ((pnX[i] - pnX[j]) * (pnX[i] - pnX[j]) +
				(pnY[i] - pnY[j]) * (pnY[i] - pnY[j]) <= pnDis[i])
				ppnMat[i][j] = 1;

	for (int k = 1; k <= nInputN; k++)
		for (int i = 1; i <= nInputN; i++)
			for (int j = 1; j <= nInputN; j++)
			{
				if (i == j || i == k || j == k)
					continue;
				if (ppnMat[i][k] && ppnMat[k][j])
					ppnMat[i][j] = 1;
			}

	for (int i = 1; i <= nInputN; i++)
	{
		nTemp = 0;
		for (int j = 1; j <= nInputN; j++)
		{
			if (ppnMat[i][j])
				nTemp++;
		}
		nAns = max(nAns, nTemp);
	}

	printf("%d", nAns);


Exit0:

	return 0;
}