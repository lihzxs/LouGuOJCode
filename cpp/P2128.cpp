/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-27 22:03
//	Comment		:	OJ(P2128)
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


void DFS(int** ppnMat, int* pnFlag, int* pnAns, int* pnNum,
	int nCount, int nN, int nSum, int& nMax)
{
	if (nSum > nMax)
		nMax = nSum;
	if (nCount > nN)
		return;


	int	nReCord;
	for (int i = 1; i <= nN; i++)
	{
		if (!pnFlag[i])
		{
			for (nReCord = 1; nReCord < nCount && 
				ppnMat[i][pnAns[nReCord]]; nReCord++);
			if (nReCord == nCount)
			{
				pnAns[nCount] = i;
				pnFlag[i] = 1;
				DFS(ppnMat, pnFlag, pnAns, pnNum,
					nCount + 1, nN, nSum + pnNum[i], nMax);
				pnFlag[i] = 0;
			}
		}///if (!pnFlag[i])
	}///for (int i = 1; i <= nN; i++)
}




int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int			nS;
	int			nE;
	int**		ppnMat		= NULL;
	int*		pnFlag		= NULL;
	int*		pnAns		= NULL;
	int*		pnNum		= NULL;
	int			nAns		= 0;

	scanf("%d%d", &nInputN, &nInputM);

	pnAns = (int*)malloc((nInputN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	pnNum = (int*)malloc((nInputN + 1) * sizeof(int));

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}
		

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnNum + i);

	for (int i = 1; i <= nInputM; i++)
	{
		scanf("%d%d", &nS, &nE);
		ppnMat[nS][nE] = 1;
		ppnMat[nE][nS] = 1;
	}

	DFS(ppnMat, pnFlag, pnAns, pnNum,
		1, nInputN, 0, nAns);

	printf("%d", nAns);




Exit0:

	return 0;
}