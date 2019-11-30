/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-10 23:26
//	Comment		:	OJ(P2910)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int**		ppnMat			= NULL;
	int*		pnSeq			= NULL;
	int			nAns			= 0;
	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1)* sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		for (int j = 1; j <= nInputN; j++)
			ppnMat[i][j] = 100001;
	}

	pnSeq = (int*)malloc(nInputM * sizeof(int));

	for (int i = 0; i < nInputM; i++)
		scanf("%d", pnSeq + i);

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputN; j++)
		{
			scanf("%d", &ppnMat[i][j]);
		}
	}

	for (int k = 1; k <= nInputN; k++)
	{
		for (int j = 1; j <= nInputN; j++)
		{
			for (int i = 1; i <= nInputN; i++)
			{
				if (i == j)
					continue;
				if (i == k || k == j)
					continue;
				if (ppnMat[i][j] > ppnMat[i][k] + ppnMat[k][j])
					ppnMat[i][j] = ppnMat[i][k] + ppnMat[k][j];
			}
		}
	}

	for (int i = 1; i < nInputM; i++)
		nAns += ppnMat[pnSeq[i - 1]][pnSeq[i]];


	printf("%d", nAns);





Exit0:

	return 0;
}