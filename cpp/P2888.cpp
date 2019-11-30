/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-2 22:09
//	Comment		:	OJ(P2888)
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
	int				nInputT;
	int				nMax;
	int				nStart;
	int				nEnd;
	int				nVal;
	int**			ppnMat				= NULL;
	scanf("%d%d%d", &nInputN, &nInputM, &nInputT);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		for (int j = 1; j <= nInputN; j++)
			ppnMat[i][j] = -1;
	}

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nVal);
		ppnMat[nStart][nEnd] = nVal;
	}

	for (int k = 1; k <= nInputN; k++)
		for (int i = 1; i <= nInputN; i++)
			for (int j = 1; j <= nInputN; j++)
			{
				if (i == j || i == k || j == k)
					continue;
				if (ppnMat[i][k] == -1)
					continue;
				if (ppnMat[k][j] == -1)
					continue;
				nMax = max(ppnMat[i][k], ppnMat[k][j]);
				if (ppnMat[i][j] == -1)
					ppnMat[i][j] = nMax;
				else
					ppnMat[i][j] = min(ppnMat[i][j], nMax);
			}
		

	for (int i = 0; i < nInputT; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		printf("%d\n", ppnMat[nStart][nEnd]);
	}


Exit0:

	return 0;
}