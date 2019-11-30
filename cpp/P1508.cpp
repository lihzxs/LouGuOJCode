/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-20 20:30
//	Comment		:	OJ(P1508)
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
int**			ppnAns = NULL;
int DFS(int** ppnMat, int nSum, int** ppnFlag, int nN,
	int nM, int nPreM, int nPreN, int& nMax)
{
	if (nPreM == 1)
		return ppnMat[nPreM][nPreN];
	if (ppnFlag[nPreM][nPreN])
		return ppnAns[nPreM][nPreN];
	for (int i = -1; i <= 1; i++)
	{
		if (nPreN + i < 1)
			continue;
		if (nPreN + i > nN)
			continue;

		ppnAns[nPreM][nPreN] = max(ppnAns[nPreM][nPreN],
			ppnMat[nPreM][nPreN] + DFS(ppnMat, 0, ppnFlag, nN, nM, nPreM - 1, nPreN + i, nMax));
		
	}
	ppnFlag[nPreM][nPreN] = 1;
	return ppnAns[nPreM][nPreN];

}

int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nTemp;
	int				nStart;
	int				nEnd;
	int				nReCord;
	int				nIndex;
	int				nMax				= 0;
	int**			ppnMat				= NULL;
	int**			ppnFlag				= NULL;


	scanf("%d%d", &nInputM, &nInputN);

	ppnMat = (int**)malloc((nInputM + 2) * sizeof(int*));
	ppnFlag = (int**)malloc((nInputM + 2) * sizeof(int*));
	ppnAns = (int**)malloc((nInputM + 2) * sizeof(int*));
	for (int i = 1; i <= nInputM + 1; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		ppnFlag[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		ppnAns[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nInputN + 1) * sizeof(int));
		memset(ppnAns[i], 0, (nInputN + 1) * sizeof(int));
	}
		


	for (int i = 1; i <= nInputM; i++)
		for (int j = 1; j <= nInputN; j++)
		{
			scanf("%d", &nTemp);
			ppnMat[i][j] = nTemp;
		}
	ppnMat[nInputM + 1][nInputN / 2 + 1] = 0;
	ppnAns[nInputM + 1][nInputN / 2 + 1] =
		DFS(ppnMat, 0, ppnFlag, nInputN, nInputM, nInputM + 1, nInputN / 2 + 1, nMax);

	printf("%d", ppnAns[nInputM + 1][nInputN / 2 + 1]);



Exit0:
	return 0;
}