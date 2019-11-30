/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-9 17:12
//	Comment		:	OJ(P2301)
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

	int				nInputN;
	int				nInputM;
	int*			pnSeq				= NULL;
	int*			pnDis				= NULL;
	int**			ppnDp				= NULL;
	int				nAns				= 10000000;
	scanf("%d%d", &nInputN, &nInputM);
	swap(nInputM, nInputN);
	pnSeq = (int*)malloc((nInputM + 1) * sizeof(int));
	pnDis = (int*)malloc((nInputM + 1) * sizeof(int));
	ppnDp = (int**)malloc((nInputM + 1) * sizeof(int*));

	for (int i = 1; i <= nInputM; i++)
		scanf("%d", pnSeq + i);

	for (int i = 0; i <= nInputM; i++)
	{
		ppnDp[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		for (int j = 0;j <= nInputN; j++)
			ppnDp[i][j] = 10000000;
		ppnDp[i][0] = 0;
	}

		
		
	sort(pnSeq + 1, pnSeq + nInputM + 1);
	for (int i = 2; i <= nInputM; i++)
	{
		pnDis[i] = pnSeq[i] - pnSeq[i - 1];
		pnDis[i] *= pnDis[i];
	}

	for (int i = 2; i <= nInputM; i++)
		for (int j = 1; j <= nInputN; j++)
			ppnDp[i][j] = min(ppnDp[i - 1][j], ppnDp[i - 2][j - 1] + pnDis[i]);

	for (int i = 2; i <= nInputM; i++)
		nAns = min(nAns, ppnDp[i][nInputN]);

	printf("%d", nAns);


Exit0:

	return 0;
}