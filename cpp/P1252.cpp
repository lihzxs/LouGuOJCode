/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-8 20:09
//	Comment		:	OJ(P1252)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;





int main(int argc, char* argv[])
{
	int*				pnSeqOutput				= NULL;
	int**				ppnMat					= NULL;
	int**				ppnMatTemp				= NULL;
	int					nMin					= 1000000;
	int					nTempIndex				= 0;
	int					nAnsSum					= 0;

	ppnMat = (int**)malloc(6 * sizeof(int*));
	ppnMatTemp = (int**)malloc(6 * sizeof(int*));
	pnSeqOutput = (int*)malloc(6 * sizeof(int));
	for (int i = 1; i < 6; i++)
	{
		pnSeqOutput[i] = 1;
		ppnMat[i] = (int*)malloc(11 * sizeof(int));
		ppnMatTemp[i] = (int*)malloc(11 * sizeof(int));
		ppnMat[i][0] = 0;
	}

	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 10; j++)
		{
			scanf("%d", &ppnMat[i][j]);
			ppnMatTemp[i][j] = ppnMat[i][j] -
				ppnMat[i][j - 1];
		}

	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			if (ppnMatTemp[j][pnSeqOutput[j] + 1] < nMin &&
				pnSeqOutput[j] + 1 <= 10)
			{
				nMin = ppnMatTemp[j][pnSeqOutput[j] + 1];
				nTempIndex = j;
			}
		}
		pnSeqOutput[nTempIndex]++;
		nMin = 1000000;

	}

	for (int i = 1; i <= 5; i++)
		nAnsSum += ppnMat[i][pnSeqOutput[i]];

	printf("%d\n%d", nAnsSum, pnSeqOutput[1]);

	for (int i = 2; i <= 5; i++)
		printf(" %d", pnSeqOutput[i]);





		
Exit0:

	return 0;
}