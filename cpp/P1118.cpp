/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 22:38
//	Comment		:	OJ(P1118)
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

bool Cmp(int& a, int& b)
{
	return a > b;
}


int main(int argc, char* argv[])
{
	int				nSum;
	int				nN;
	int**			ppnMat				= NULL;
	int*			pnSeq				= NULL;
	int				nS;
	scanf("%d%d", &nN, &nSum);

	ppnMat = (int**)malloc((nN + 1) * sizeof(int*));
	pnSeq = (int*)malloc((nN + 1) * sizeof(int));

	for (int i = 1; i <= nN; i++)
		pnSeq[i] = i;

	for (int i = 1; i <= nN; i++)
		ppnMat[i] = (int*)malloc((nN + 1) * sizeof(int));

	for (int i = 1; i <= nN; i++)
		ppnMat[i][1] = ppnMat[i][i] = 1;

	for (int i = 3; i <= nN; i++)
		for (int k = 1; k <= (i - 1) / 2; k++)
		{
			ppnMat[i][k + 1] = ppnMat[i][i - k] = 
				ppnMat[i - 1][k] + ppnMat[i - 1][k + 1];
		}

	do
	{
		nS = 0;
		for (int i = 1; i <= nN; i++)
		{
			nS += pnSeq[i] * ppnMat[nN][i];
			if (nS > nSum)
			{
				sort(pnSeq + i, pnSeq + nN + 1, Cmp);
				break;
			}
		}
		if (nS == nSum)
		{
			for (int i = 1; i <= nN; i++)
				printf("%d ", pnSeq[i]);
			break;
		}

	} while (next_permutation(pnSeq + 1, pnSeq + nN + 1));


Exit0:

	return 0;
}