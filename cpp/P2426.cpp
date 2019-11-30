/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-4 21:45
//	Comment		:	OJ(P2426)
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
	int				nInputN;
	int*			pnSeq				= NULL;
	int**			ppnDp				= NULL;
	int				nAns				= 0;

	scanf("%d", &nInputN);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	ppnDp = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnDp[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		for (int j = 1; j <= nInputN; j++)
			ppnDp[i][j] = 0;

		ppnDp[i][1] = pnSeq[i];
	}
	for (int j = 2; j <= nInputN; j++)
		for (int i = 1; i <= nInputN - j + 1; i++)
		{
			ppnDp[i][j] = j * abs(pnSeq[i] - pnSeq[i + j - 1]);
			for (int k = 1; k < j; k++)
				ppnDp[i][j] = max(ppnDp[i][j], ppnDp[i][k] + ppnDp[k + i][j - k]);

		}
		
	for (int i = 1; i <= nInputN; i++)
		nAns = max(nAns, ppnDp[i][nInputN]);

	printf("%d", nAns);



Exit0:
	return 0;
}