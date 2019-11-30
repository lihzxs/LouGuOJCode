/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-8 00:54
//	Comment		:	OJ(P2196)
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

int				pnAns[30];
int				nC;
map<int, int>	mpNum;
map<int, bool>	mpFlag;

void DFS(int** ppnMat, int* pnPoint, int nN, int nCount, int nSum, int& nMax)
{
	
	if (nMax < nSum)
	{
		nMax = nSum;
		nC = nCount;
		for (int i = 1; i < nCount; i++)
			pnAns[i] = pnPoint[i];
	}
	if (nCount > nN)
		return;
	for (int i = 1; i <= nN; i++)
	{
		if (ppnMat[pnPoint[nCount - 1]][i] && !mpFlag[i])
		{
			mpFlag[i] = 1;
			pnPoint[nCount] = i;
			DFS(ppnMat, pnPoint, nN, nCount + 1, nSum + mpNum[i], nMax);
			mpFlag[i] = 0;
		}
	}
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nTemp;

	int*			pnPoint			= NULL;
	int				nAns			= 0;
	int**			ppnMat			= NULL;
	
	scanf("%d", &nInputN);
	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", &nTemp);
		mpNum[i] = nTemp;
	}

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	pnPoint = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 0; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}
	for (int i = 1; i <= nInputN; i++)
		ppnMat[0][i] = 1;

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = i + 1; j <= nInputN; j++)
		{
			scanf("%d", &nTemp);
			ppnMat[i][j] = nTemp;
		}
	}
	pnPoint[0] = 0;
	DFS(ppnMat, pnPoint, nInputN, 1, 0, nAns);

	for (int i = 1; i < nC; i++)
		printf("%d ", pnAns[i]);
	printf("\n%d\n", nAns);
		
Exit0:

	return 0;
}