/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-4 23:27
//	Comment		:	OJ(P2853)
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

void DFS(int** ppnMat, int* pnFlag, int nN, int nStart)
{
	if (pnFlag[nStart])
		return;
	pnFlag[nStart] = 1;
	for (int i = 1; i <= nN; i++)
	{
		if (ppnMat[nStart][i])
			DFS(ppnMat, pnFlag, nN, i);
	}	
}



int main(int argc, char* argv[])
{
	int				nInputK;
	int				nInputN;
	int				nInputM;
	int				nStart;
	int				nEnd;
	int				nAddItem;
	int				nAns			= 0;
	int**			pnLocal;
	int**			ppnMat			= NULL;

	scanf("%d%d%d", &nInputK, &nInputN, &nInputM);
	pnLocal = (int**)malloc((nInputK + 1) * sizeof(int*));

	for (int i = 1; i <= nInputK; i++)
	{
		pnLocal[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(pnLocal[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputK; i++)
		scanf("%d", &pnLocal[i][0]);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}
	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		ppnMat[nStart][nEnd] = 1;
	}

	for (int i = 1; i <= nInputK; i++)
		DFS(ppnMat, pnLocal[i], nInputN, pnLocal[i][0]);
		
	for (int i = 1; i <= nInputN; i++)
	{
		nAddItem = 1;
		for (int j = 1; j <= nInputK; j++)
		{
			if (!pnLocal[j][i])
			{
				nAddItem = 0;
				break;
			}
		}
		nAns += nAddItem;
	}

	printf("%d", nAns);

Exit0:
	return 0;
}