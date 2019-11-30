/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-8 00:15
//	Comment		:	OJ(P2935)
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
	int			nInputP;
	int			nInputF;
	int			nInputC;
	int			nStart;
	int			nEnd;
	int			nDis;
	int**		ppnMat				= NULL;
	int*		pnSeqF				= NULL;
	int			nMin				= INT32_MAX - 1;
	int			nIndex				= 600;
	long long			nSum;
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%d%d%d", &nInputP, &nInputF, &nInputC);

	ppnMat = (int**)malloc((nInputP + 1) * sizeof(int*));
	for (int i = 1; i <= nInputP; i++)
	{
		ppnMat[i] = (int*)malloc((nInputP + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputP + 1) * sizeof(int));
	}
	pnSeqF = (int*)malloc(nInputF * sizeof(int));

	for (int i = 0; i < nInputF; i++)
		scanf("%d", pnSeqF + i);

	for (int i = 0; i < nInputC; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nDis);
		ppnMat[nStart][nEnd] = ppnMat[nEnd][nStart] = nDis;
	}


	for (int k = 1; k <= nInputP; k++)
		for (int i = 1; i <= nInputP; i++)
			for (int j = 1; j <= nInputP; j++)
			{
				if (i == j || i == k || j == k)
					continue;
				if (ppnMat[i][k] != 0 && ppnMat[k][j] != 0)
				{
					if (ppnMat[i][j] == 0)
						ppnMat[i][j] = ppnMat[i][k] + ppnMat[k][j];
					else
						ppnMat[i][j] = min(ppnMat[i][j], ppnMat[i][k] + ppnMat[k][j]);
				}
			}
				


	for (int i = 1; i <= nInputP; i++)
	{
		nSum = 0;
		for (int j = 0; j < nInputF; j++)
		{
			if (i == pnSeqF[j])
				continue;
			if (ppnMat[i][pnSeqF[j]] == 0)
			{
				nSum = INT32_MAX;
				break;
			}
			nSum += ppnMat[i][pnSeqF[j]];
			if (nSum > nMin)
			{
				nSum = INT32_MAX;
				break;
			}
		}
			
		if (nSum < nMin)
		{
			nMin = nSum;
			//nIndex = min(i, nIndex);
			nIndex = i;
		}
	}

	printf("%d", nIndex);
Exit0:

	return 0;
}