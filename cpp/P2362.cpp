/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-13 16:05
//	Comment		:	OJ(P2362)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnCount				= NULL;
	int*			pnFlag				= NULL;
	int*			pnAns				= NULL;
	int				nInputM;
	int				nPreNum;
	int				nPreCount;
	int				nMax;
	int				nTemp;
	int				nCount				= 0;
	int				nCountMax			= 0;
	int				nMaxIndex			= 0;
	scanf("%d", &nInputN);
	pnCount = (int*)malloc(151 * sizeof(int));
	pnFlag = (int*)malloc(151 * sizeof(int));
	pnAns = (int*)malloc(151 * sizeof(int));
	while (nInputN--)
	{
		nMax = 0;
		nCount = 0;
		nCountMax = 0;
		nMaxIndex = 0;
		memset(pnCount, 0, 151 * sizeof(int));
		memset(pnFlag, 0, 151 * sizeof(int));
		memset(pnAns, 0, 151 * sizeof(int));
		scanf("%d", &nInputM);
		for (int i = 0; i < nInputM; i++)
		{
			scanf("%d", pnFlag + i);
			pnCount[i] = 1;
			for (int j = i - 1; j >= 0; j--)
			{
				if (pnFlag[j] <= pnFlag[i] && pnCount[j] + 1 > pnCount[i])
				{
					pnCount[i] = pnCount[j] + 1;
					pnAns[i] = pnAns[j];
				}
				else if (pnFlag[j] <= pnFlag[i] && pnCount[j] + 1 == pnCount[i])
					pnAns[i]++;
					
			}

			if (pnCount[i] >= nMax)
			{
				nMax = pnCount[i];
				nMaxIndex = i;
			}
		}


		for (int i = 0; i < nInputM; i++)
		{
			if (pnCount[i] == nMax)
				nCount += pnAns[i];
		}

		printf("%d %d\n", nMax, nCount + 1);


	}






Exit0:

	return 0;
}