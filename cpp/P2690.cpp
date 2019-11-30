/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-20 23:29
//	Comment		:	OJ(P2690)
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
#define	MAXNUM		10010
#define	EPS         0.001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int			nInputT;
	int			nInputW;
	int*		pnSeq					= NULL;
	int**		ppDp					= NULL;
	int			nAns					= 0;

	scanf("%d%d", &nInputT, &nInputW);

	pnSeq = (int*)malloc((nInputT + 1) * sizeof(int));

	for (int i = 1; i <= nInputT; i++)
		scanf("%d", pnSeq + i);

	ppDp = (int**)malloc((nInputT + 1) * sizeof(int*));

	for (int i = 0; i <= nInputT; i++)
	{
		ppDp[i] = (int*)malloc((nInputW + 1) * sizeof(int));
		memset(ppDp[i], 0, (nInputW + 1) * sizeof(int));
	}


	for (int i = 1; i <= nInputT; i++)
		for (int j = 0; j <= nInputT && j <= nInputW; j++)
		{
			if (j == 0)
				ppDp[i][j] = ppDp[i - 1][j];
			else
				ppDp[i][j] = max(ppDp[i - 1][j], ppDp[i - 1][j - 1]);
			if (pnSeq[i] == j % 2 + 1)
				ppDp[i][j]++;
		}

	for (int i = 1; i <= nInputW; i++)
		nAns = max(nAns, ppDp[nInputT][i]);

	printf("%d", nAns);




Exit0:
	return 0;
}