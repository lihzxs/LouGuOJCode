/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-20 17:33
//	Comment		:	OJ(P1475)
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


void DFS(int* pnFlag, int* pnC, int* pnOwn, 
	int nMax, int** ppnCount, int nX)
{
	if (pnFlag[nX])
		return;
	pnFlag[nX] = 1;

	for (int i = nMax; i >= 1; i--)
	{
		pnC[i] += ppnCount[nX][i];
		if (pnC[i] > 50)
		{
			pnOwn[i] = 1;
			DFS(pnFlag, pnC, pnOwn,
				nMax, ppnCount, i);
		}
	}

}

int main(int argc, char* argv[])
{
	int				nInputN;
	int**			ppnCount				= NULL;
	int*			pnC					= NULL;
	int*			pnFlag					= NULL;
	int*			pnOwn					= NULL;
	int				nMax					= 0;
	int				nStart;
	int				nEnd;
	int				nVal;

	ppnCount = (int**)malloc(105 * sizeof(int*));
	pnC = (int*)malloc(105 * sizeof(int));
	pnFlag = (int*)malloc(105 * sizeof(int));
	pnOwn = (int*)malloc(105 * sizeof(int));

	for (int i = 1; i <= 100; i++)
	{
		ppnCount[i] = (int*)malloc(105 * sizeof(int));
		memset(ppnCount[i], 0, 105 * sizeof(int));
	}

	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nVal);
		ppnCount[nStart][nEnd] = nVal;
		nMax = max(nMax, nStart);
		nMax = max(nMax, nEnd);
	}


	for (int i = 1; i <= nMax; i++)
	{
		memset(pnFlag, 0, 105 * sizeof(int));
		memset(pnOwn, 0, 105 * sizeof(int));
		memset(pnC, 0, 105 * sizeof(int));
		DFS(pnFlag, pnC, pnOwn,
			nMax, ppnCount, i);
		for (int j = 1; j <= nMax; j++)
		{
			if (pnOwn[j] && i != j)
				printf("%d %d\n", i, j);
		}
	}


Exit0:

	return 0;
}