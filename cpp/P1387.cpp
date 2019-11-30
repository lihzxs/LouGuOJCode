/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-28 22:53
//	Comment		:	OJ(P1387)
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
	int			nInputN;
	int			nInputM;
	int			nTemp;
	int			nMax				= 0;
	int			nFlag				= 0;
	int**		ppnMat				= NULL;
	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			scanf("%d", &nTemp);
			ppnMat[i][j] = nTemp;
		}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			nFlag = 0;
			if (ppnMat[i][j])
			{
				for (int k = 1; k <= min(nInputN - i, nInputM - j); k++)
				{
					if (nFlag)
						break;
					for (int z = j; z <= j + k; z++)
						if (!ppnMat[i + k][z])
						{
							nMax = max(nMax, k);
							nFlag = 1;
							break;
						}
					for (int z = i; z <= i + k; z++)
						if (!ppnMat[z][j + k])
						{
							nMax = max(nMax, k);
							nFlag = 1;
							break;
						}
				}
			}
		}

	printf("%d", nMax);

Exit0:

	return 0;
}