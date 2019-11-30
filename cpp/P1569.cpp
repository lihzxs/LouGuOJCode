/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-15 21:21
//	Comment		:	OJ(P1569)
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
	int				nInputN;
	int*			pnSeq				= NULL;
	int*			pnSum				= NULL;
	int*			pnDp				= NULL;
	scanf("%d", &nInputN);


	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pnSum = (int*)malloc((nInputN + 1) * sizeof(int));
	pnDp = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnDp, 0, (nInputN + 1) * sizeof(int));
	pnSum[0] = 0;
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	for (int i = 1; i <= nInputN; i++)
	{
		pnSum[i] = pnSeq[i - 1] + pnSum[i - 1];
		if (pnSum[i] >= 0)
			pnDp[i] = 1;
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j < i; j++)
		{
			if (pnDp[j] > 0 && pnSum[i] - pnSum[j] >= 0)
				pnDp[i] = max(pnDp[i], pnDp[j] + 1);
		}
		

	if (pnDp[nInputN] == 0)
		printf("Impossible");
	else
		printf("%d", pnDp[nInputN]);
		




Exit0:

	return 0;
}