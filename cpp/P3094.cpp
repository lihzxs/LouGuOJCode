/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-29 16:43
//	Comment		:	OJ(P3094)
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
#define	MAXNUM		201
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int			nInputK;
	int			nInputQ;
	int			nStart;
	int			nEnd;
	int			nW;
	int			nMin;
	long long	llSum = 0;
	int			nCount = 0;
	int**		ppnMat = NULL;
	scanf("%d%d%d%d", &nInputN, &nInputM, &nInputK, &nInputQ);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		for (int j = 1; j <= nInputN; j++)
			ppnMat[i][j] = 100000000;
	}
	for (int i = 1; i <= nInputN; i++)
		ppnMat[i][i] = 0;
	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nW);
		ppnMat[nStart][nEnd] = min(ppnMat[nStart][nEnd], nW);
	}

	for (int k = 1; k <= nInputN; k++)
		for (int i = 1; i <= nInputN; i++)
			for (int j = 1; j <= nInputN; j++)
			{
				if (i == j || k == i || k == j)
					continue;
				ppnMat[i][j] = min(ppnMat[i][j],
					ppnMat[i][k] + ppnMat[k][j]);
			}

	for (int i = 0; i < nInputQ; i++)
	{
		nMin = 100000000;
		scanf("%d%d", &nStart, &nEnd);
		for (int j = 1; j <= nInputK; j++)
			nMin = min(ppnMat[nStart][j] + ppnMat[j][nEnd], nMin);
		if (nMin != 100000000)
		{
			nCount++;
			llSum += nMin;
		}

	}


	printf("%d\n%lld\n", nCount, llSum);


Exit0:

	return 0;
}