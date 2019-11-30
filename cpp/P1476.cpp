/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-12 23:24
//	Comment		:	OJ(P1476)
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
	int					nInputN;
	int					nInputM;
	int					nStart;
	int					nEnd;
	int**				ppnMat					= NULL;

	scanf("%d%d", &nInputN, &nInputM);
	ppnMat = (int**)malloc((nInputN + 2) * sizeof(int*));
	
	for (int i = 1; i <= nInputN + 1; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 2) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 2) * sizeof(int));
	}


	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		scanf("%d", &ppnMat[nStart][nEnd]);
	}

	for (int k = 1; k <= nInputN + 1; k++)
		for (int i = 1; i <= nInputN + 1; i++)
			for (int j = 1; j <= nInputN + 1; j++)
			{
				if (i == j || i == k || j == k)
					continue;
				if (!ppnMat[i][k])
					continue;
				if (!ppnMat[k][j])
					continue;
				if (!ppnMat[i][j])
					ppnMat[i][j] = ppnMat[i][k] + ppnMat[k][j];
				else
					ppnMat[i][j] = max(ppnMat[i][j], ppnMat[i][k] + ppnMat[k][j]);
			}

	printf("%d\n", ppnMat[1][nInputN + 1]);

	for (int i = 1; i <= nInputN + 1; i++)
		if (ppnMat[1][nInputN + 1] == ppnMat[1][i] + ppnMat[i][nInputN + 1])
			printf("%d ", i);

Exit0:

	return 0;
}