/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-11 21:38
//	Comment		:	OJ(P1346)
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
	int				nStart;
	int				nEnd;
	int				nK;
	int				nTemp;
	int**			ppnMat				= NULL;

	scanf("%d%d%d", &nInputN, &nStart, &nEnd);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", &nK);
		for (int j = 0; j < nK; j++)
		{
			scanf("%d", &nTemp);
			if (j == 0)
				ppnMat[i][nTemp] = 1;
			else
				ppnMat[i][nTemp] = 2;
		}
	}

	for (int k = 1; k <= nInputN; k++)
		for (int i = 1; i <= nInputN; i++)
			for (int j = 1; j <= nInputN; j++)
			{
				if (i == j || i == k || j == k)
					continue;
				if (ppnMat[i][k] == 0)
					continue;
				if (ppnMat[k][j] == 0)
					continue;
				if (ppnMat[i][j] == 0)
					ppnMat[i][j] = ppnMat[i][k] + ppnMat[k][j] - 1;
				else
					ppnMat[i][j] = min(ppnMat[i][j] - 1, ppnMat[i][k] + ppnMat[k][j] - 2) + 1;
			}
	printf("%d", ppnMat[nStart][nEnd] - 1);


Exit0:

	return 0;
}