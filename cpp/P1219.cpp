/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-19 21:33
//	Comment		:	OJ(P1219)
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int			nFlag1[100];
int			nFlag2[100];

int			nFlag3[100];


void DFS(int** ppnFlag, int* pnReCord, int nPre,
	int nCount, int nN, int& nAns)
{
	if (nCount >= nN + 1)
	{
		nAns++;
		if (nAns <= 3)
		{
			for (int i = 1; i < nCount; i++)
				printf("%d ", pnReCord[i]);
			printf("\n");
		}
		return;
	}

	for (int i = 1; i <= nN; i++)
	{
		if (!nFlag3[i] && !nFlag1[nCount + i] && !nFlag2[nCount - i + nN])
		{
			nFlag3[i] = 1;
			ppnFlag[nCount][i] = 1;
			nFlag2[nCount - i + nN] = 1;
			nFlag1[nCount + i] = 1;
			pnReCord[nCount] = i;
			DFS(ppnFlag, pnReCord, i, nCount + 1, nN, nAns);
			ppnFlag[nCount][i] = 0;
			nFlag2[nCount - i + nN] = 0;
			nFlag1[nCount + i] = 0;
			nFlag3[i] = 0;
		}
	}
}

int main(int argc, char* argv[])
{
	int					nInputN;
	int**				ppnFlag				= NULL;
	int*				pnReCord			= NULL;
	int					nAns				= 0;
	scanf("%d", &nInputN);

	ppnFlag = (int**)malloc((nInputN + 1) * sizeof(int*));
	pnReCord = (int*)malloc((nInputN + 2) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnFlag[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nInputN + 1) * sizeof(int));
	}

	DFS(ppnFlag, pnReCord, 0, 1, nInputN, nAns);

	printf("%d", nAns);

Exit0:

	return 0;
}