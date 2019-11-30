/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-18 20:04
//	Comment		:	OJ(P1239)
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
	int					nInputN;
	int*				pnCount				= NULL;
	int*				pnTemp				= NULL;
	int					nNum;
	int					nTemp;
	scanf("%d", &nInputN);
	pnCount = (int*)malloc(11 * sizeof(int));
	memset(pnCount, 0, 11 * sizeof(int));

	pnTemp = (int*)malloc(11 * sizeof(int));
	memset(pnTemp, 0, 11 * sizeof(int));

	nNum = nInputN / 10000;

	if (nInputN < 10000)
	{
		for (int i = 1; i <= nInputN; i++)
		{
			nTemp = i;
			while (nTemp != 0)
			{
				pnCount[nTemp % 10]++;
				nTemp /= 10;
			}
		}///for (int i = 1; i <= nInputN; i++)
	}
	else
	{
		for (int i = 1; i < 10000; i++)
		{
			nTemp = i;
			while (nTemp != 0)
			{
				pnCount[nTemp % 10]++;
				nTemp /= 10;
			}
		}

		for (int i = 1; i < nNum; i++)
		{
			memset(pnTemp, 0, 11 * sizeof(int));
			nTemp = i;
			while (nTemp != 0)
			{
				pnTemp[nTemp % 10]++;
				nTemp /= 10;
			}

			for (int j = 0; j <= 9; j++)
				pnCount[j] += pnTemp[j] * 10000;

		}

		for (int i = 0; i <= 9; i++)
			pnCount[i] += 4000 * (nNum - 1);

		for (int i = nNum * 10000; i <= nInputN; i++)
		{
			nTemp = i;
			while (nTemp != 0)
			{
				pnCount[nTemp % 10]++;
				nTemp /= 10;
			}
		}

	}

	for (int i = 0; i <= 9; i++)
		printf("%d\n", pnCount[i]);


Exit0:

	return 0;
}