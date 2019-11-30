/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-3 16:54
//	Comment		:	OJ(P1692)
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



void DFS(int** ppnMat, int nN, int* pnS, int* pnAns,
	int nPre, int nCount, int& nMax)
{
	if (nPre == nN + 1)
	{
		if (nCount > nMax)
		{
			for (int i = 1; i <= nN; i++)
				pnAns[i] = pnS[i];
			nMax = nCount;
		}
			
		return;
	}
	

	int nFlag = 1;
	for (int j = 1; j < nPre; j++)
	{
		if (pnS[j] && ppnMat[nPre][j])
		{
			nFlag = 0;
			break;
		}
	}
	if (nFlag)
	{
		pnS[nPre] = 1;
		DFS(ppnMat, nN, pnS, pnAns,
			nPre + 1, nCount + 1, nMax);
		pnS[nPre] = 0;
	}
	DFS(ppnMat, nN, pnS, pnAns,
		nPre + 1, nCount, nMax);
}




int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int*			pnS = NULL;
	int*			pnAns = NULL;
	int**			ppnMat			= NULL;
	int				nInputA;
	int				nInputB;
	int				nMax			= 0;
	int				nCount			= 0;
	scanf("%d%d", &nInputN, &nInputM);

	pnS = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnS, 0, (nInputN + 1) * sizeof(int));
	pnAns = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnAns, 0, (nInputN + 1) * sizeof(int));
	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}
		


	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nInputA, &nInputB);
		ppnMat[nInputA][nInputB] = ppnMat[nInputB][nInputA] = 1;
	}

	
	DFS(ppnMat, nInputN, pnS, pnAns, 1, 0, nMax);

	printf("%d\n", nMax);
	for (int i = 1; i <= nInputN; i++)
		printf("%d ", pnAns[i]);



Exit0:
	return 0;
}