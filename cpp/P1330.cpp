/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-23 16:47
//	Comment		:	OJ(P1330)
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

void DFS(int* pnFlag, int* pnSeq, vector<int>* vecMat, 
	int nN, int nIndex, int nNum, int& nTemp)
{
	if (pnSeq[nIndex] != -1 && pnSeq[nIndex] != nNum)
	{
		printf("Impossible");
		exit(0);
	}
	if (pnSeq[nIndex] == nNum)
		return;
	pnSeq[nIndex] = nNum;
	pnFlag[nIndex] = 1;
	nTemp++;

	for (int i = 0; i < vecMat[nIndex].size(); i++)
		DFS(pnFlag, pnSeq, vecMat,
			nN, vecMat[nIndex][i], nNum^1, nTemp);
}




int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	vector<int>*	vecMat;
	int				nStart;
	int				nEnd;
	int				nAns = 0;
	int				nTemp;
	int*			pnFlag = NULL;
	int*			pnSeq = NULL;
	int				nSum = 0;

	scanf("%d%d", &nInputN, &nInputM);

	vecMat = new vector<int>[nInputN + 1];
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputM; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		vecMat[nStart].push_back(nEnd);
		vecMat[nEnd].push_back(nStart);
	}

	for (int i = 1; i <= nInputN; i++)
	{
		if (pnFlag[i])
			continue;
		nTemp = 0;

		for (int j = 1; j <= nInputN; j++)
			pnSeq[j] = -1;
		DFS(pnFlag, pnSeq, vecMat,
			nInputN, i, 0, nTemp);
		nSum = 0;
		for (int i = 1; i <= nInputN; i++)
			if (pnSeq[i] == 1)
				nSum++;
		nAns += min(nTemp - nSum, nSum);
	}

	printf("%d", nAns);



Exit0:

	return 0;
}