/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-16 20:31
//	Comment		:	OJ(P17119)
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


inline int Sum(int nStartX, int nStartY, int nEndX, int nEndY, int** ppnMat)
{
	int		nSum = 0;

	for (int i = nStartX; i <= nEndX; i++)
		for (int j = nStartY; j <= nEndY; j++)
			nSum += ppnMat[i][j];

	return nSum;
}

int main(int argc, char* argv[])
{
	int				nInputN;
	int**			pnRecord = NULL;
	int**			ppnMat = NULL;
	int				nMax = 0;
	int				nTemp;

	scanf("%d", &nInputN);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	pnRecord = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 0; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		pnRecord[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(pnRecord[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
			scanf("%d", &ppnMat[i][j]);

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
			pnRecord[i][j] = pnRecord[i - 1][j] +
			pnRecord[i][j - 1] + ppnMat[i][j] - pnRecord[i - 1][j - 1];






	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
		{
			for (int k = i; k <= nInputN; k++)
				for (int l = j; l <= nInputN; l++)
				{
					nTemp = pnRecord[k][l] - 
						pnRecord[i - 1][l] - pnRecord[k][j - 1] + pnRecord[i - 1][j - 1];
					nMax = max(nTemp, nMax);
				}
		}


	printf("%d", nMax);





Exit0:

	return 0;
}