/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-3 22:43
//	Comment		:	OJ(P3399)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int*		pnSeqD				= NULL;
	int*		pnSeqC				= NULL;
	int			nMin				= INT32_MAX;
	int**		ppnDp				= NULL;

	scanf("%d%d", &nInputN, &nInputM);


	pnSeqD = (int*)malloc(nInputN * sizeof(int));
	pnSeqC = (int*)malloc(nInputM * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeqD + i);

	for (int j = 0; j < nInputM; j++)
		scanf("%d", pnSeqC + j);

	ppnDp = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 0; i <= nInputN; i++)
	{
		ppnDp[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		for (int j = 0; j <= nInputM; j++)
		{
			if (i != 0)
				ppnDp[i][j] = INT32_MAX;
			else
				ppnDp[i][j] = 0;
		}
			
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = i; j <= nInputM; j++)
			ppnDp[i][j] = min(ppnDp[i][j - 1], ppnDp[i - 1][j - 1] + pnSeqD[i - 1] * pnSeqC[j - 1]);

	for (int i = nInputN; i <= nInputM; i++)
		nMin = min(nMin, ppnDp[nInputN][i]);

	printf("%d", nMin);
Exit0:
	return 0;
}