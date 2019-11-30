/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-24 21:15
//	Comment		:	OJ(P3906)
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
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	int					nN;
	int					nM;
	int					nK;
	int**				ppnMat				= NULL;
	int					nStart;
	int					nEnd;
	int*				pnPoint				= NULL;
	int					nIndex;
	
	scanf("%d%d", &nN, &nM);

	ppnMat = (int**)malloc((nN + 1) * sizeof(int*));
	pnPoint = (int*)malloc((nN + 1) * sizeof(int));
	for (int i = 1; i <= nN; i++)
	{
		ppnMat[i] = (int*)malloc((nN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nN + 1) * sizeof(int));
	}

	for (int i = 0; i < nM; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		ppnMat[nStart][nEnd] = 1;
		ppnMat[nEnd][nStart] = 1;
	}

	for (int k = 1; k <= nN; k++)
		for (int i = 1; i <= nN; i++)
			for (int j = 1; j <= nN; j++)
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
					ppnMat[i][j] = min(ppnMat[i][j], ppnMat[i][k] + ppnMat[k][j]);
			}
	scanf("%d", &nK);

	for (int i = 0; i < nK; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		nIndex = 0;
		pnPoint[nIndex++] = nStart;
		for (int j = 1; j <= nN; j++)
			if (ppnMat[nStart][j] && ppnMat[j][nEnd] &&
				ppnMat[nStart][j] + ppnMat[j][nEnd] == ppnMat[nStart][nEnd])
				pnPoint[nIndex++] = j;

		pnPoint[nIndex++] = nEnd;

		sort(pnPoint, pnPoint + nIndex);

		for (int j = 0; j < nIndex; j++)
			printf("%d ", pnPoint[j]);
		printf("\n");
	}




Exit0:
	return 0;
}