/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 16:34
//	Comment		:	OJ(P2335)
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
	int					nInputN;
	int					nInputM;
	int**				ppnMat				= NULL;
	int*				pnX					= NULL;
	int*				pnY					= NULL;
	int					nCount				= 0;
	int					nMin;

	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	pnX = (int*)malloc((nInputN * nInputN + 1) * sizeof(int));
	pnY = (int*)malloc((nInputN * nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			scanf("%d", &ppnMat[i][j]);
			if (ppnMat[i][j] == 1)
			{
				ppnMat[i][j] = -1;
				pnX[nCount] = i;
				pnY[nCount] = j;
				nCount++;
			}
		}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			if (ppnMat[i][j] != -1)
			{
				nMin = 1000000000;
				for (int k = 0; k < nCount; k++)
					nMin = min(nMin, abs(pnX[k] - i) + abs(pnY[k] - j));
				ppnMat[i][j] = nMin;
			}
		}

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputM; j++)
		{
			if (ppnMat[i][j] == -1)
				printf("0 ");
			else
				printf("%d ", ppnMat[i][j]);
		}
		printf("\n");
	}
		


Exit0:

	return 0;
}