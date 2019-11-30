/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-1 15:36
//	Comment		:	OJ(P2126)
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
	int				nInputN;
	int				nInputM;
	int**			ppnMat = NULL;
	unsigned int*	pnDis = 0;
	int*			pnFlag = NULL;
	int				nTemp;
	int				nStart;
	int				nEnd;
	int				nLong;
	int				nX;
	int				nY;
	int				nW;
	int				nMin;
	int				nPoint;
	int				nSum = 0;

	scanf("%d", &nInputN);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	pnDis = (unsigned int*)malloc((nInputN + 1) * sizeof(unsigned int));
	memset(pnDis, 127, (nInputN + 1) * sizeof(int));

	for (int i = 0; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		for (int j = 0; j <= nInputN; j++)
			ppnMat[i][j] = 2147000000;
	}

	scanf("%d", &nInputM);
	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nLong);
		ppnMat[nStart][nEnd] = min(ppnMat[nStart][nEnd], nLong);
		ppnMat[nEnd][nStart] = ppnMat[nStart][nEnd];
	}



	for (int i = 0; i <= nInputN; i++)
		pnDis[i] = 2147000000;
	pnDis[0] = 0;
	for (int i = 0; i < nInputN; i++)
	{
		nMin = 2147000000;
		for (int j = 0; j <= nInputN; j++)
		{
			if (pnDis[j] < nMin && pnFlag[j] == false)
			{
				nMin = pnDis[j];
				nPoint = j;
			}
		}

		pnFlag[nPoint] = true;

		for (int j = 0; j <= nInputN; j++)
		{

				if (pnDis[j] > ppnMat[nPoint][j] && pnFlag[j] == false)
					pnDis[j] = ppnMat[nPoint][j];

		}
	}

	for (int i = 0; i <= nInputN; i++)
		nSum += pnDis[i];

	printf("%d", nSum);

Exit0:

	return 0;
}