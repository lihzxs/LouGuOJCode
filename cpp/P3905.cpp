/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-9 20:42
//	Comment		:	OJ(P3905)
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
	int**			ppnMat					= NULL;
	int				nInputM;
	int				nStart;
	int				nEnd;
	int				nLong;
	map<int, map<int, int> >			mpStore;
	scanf("%d", &nInputN);
	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		for (int j = 1; j <= nInputN; j++)
			ppnMat[i][j] = 10000000;
	}
		
	scanf("%d", &nInputM);

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nLong);
		mpStore[nStart][nEnd] = mpStore[nEnd][nStart] = nLong;
		ppnMat[nStart][nEnd] = ppnMat[nEnd][nStart] = 0;
	}


	scanf("%d", &nInputM);
	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		ppnMat[nStart][nEnd] = ppnMat[nEnd][nStart] = 
			mpStore[nStart][nEnd];
	}

	scanf("%d%d", &nStart, &nEnd);
	
	for (int k = 1; k <= nInputN; k++)
		for (int i = 1; i <= nInputN; i++)
			for (int j = 1; j <= nInputN; j++)
			{
				if (i == j || i == k || j == k)
					continue;
				ppnMat[i][j] = min(ppnMat[i][j], 
					ppnMat[i][k] + ppnMat[k][j]);
			}

	printf("%d", ppnMat[nStart][nEnd]);


Exit0:

	return 0;
}