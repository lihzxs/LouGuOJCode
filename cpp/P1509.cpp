
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-22 23:52
//	Comment		:	OJ(P1509)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int					nInputN;
	int*				pnRMB				= NULL;
	int*				pnRP				= NULL;
	int*				pnTime				= NULL;
	int					nRMB;
	int					nR;
	int					nTemp;
	int					nNow;
	int					nNext;
	int**				ppnBagFrom			= NULL;
	int**				ppnTime				= NULL;
	scanf("%d", &nInputN);
	pnRMB = (int*)malloc(nInputN * sizeof(int));
	pnRP = (int*)malloc(nInputN * sizeof(int));
	pnTime = (int*)malloc(nInputN * sizeof(int));


	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &pnRMB[i]);
		scanf("%d", &pnRP[i]);
		scanf("%d", &pnTime[i]);
	}

	scanf("%d%d", &nRMB, &nR);

	ppnBagFrom = (int**)malloc((nRMB + 1) * sizeof(int*));
	ppnTime = (int**)malloc((nRMB + 1) * sizeof(int*));
	for (int i = 0; i <= nRMB; i++)
	{
		ppnBagFrom[i] = (int*)malloc((nR + 1) * sizeof(int));
		memset(ppnBagFrom[i], 0, (nR + 1) * sizeof(int));
		ppnTime[i] = (int*)malloc((nR + 1) * sizeof(int));
		memset(ppnTime[i], 0, (nR + 1) * sizeof(int));
	}

	for (int i = 0; i < nInputN; i++)
	{
		for (int j = nRMB; j >= pnRMB[i]; j--)
			for (int k = nR; k >= pnRP[i]; k--)
			{
				nNow = ppnBagFrom[j][k];
				nNext = ppnBagFrom[j - pnRMB[i]][k - pnRP[i]] + 1;
				ppnBagFrom[j][k] = max(nNow, nNext);
				if (nNow == nNext)
					ppnTime[j][k] = min(ppnTime[j - pnRMB[i]][k - pnRP[i]] + pnTime[i], 
						ppnTime[j][k]);
				if (nNext > nNow)
					ppnTime[j][k] = ppnTime[j - pnRMB[i]][k - pnRP[i]] + pnTime[i];
			}
				
	}

	printf("%d", ppnTime[nRMB][nR]);


Exit0:

	return 0;
}