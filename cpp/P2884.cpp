/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-5 23:49
//	Comment		:	OJ(P2884)
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

bool Check(int* pnSum, int nN, int nM, int nX)
{
	int nPre = 0;
	int	nCount = 0;
	for (int i = 1; i <= nN; i++)
	{
		if (pnSum[i] - nPre > nX)
		{
			nCount++;
			nPre = pnSum[i - 1];
		}
	}
	return nCount >= nM;
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nMax			= 0;
	int*			pnSum			= NULL;
	int				nTemp;
	int				nLeft;
	int				nRight;
	int				nMid;

	scanf("%d%d", &nInputN, &nInputM);


	pnSum = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSum[0] = 0;

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", &nTemp);
		nMax = max(nTemp, nMax);
		pnSum[i] = nTemp + pnSum[i - 1];
	}

	nLeft = nMax;
	nRight = pnSum[nInputN];

	while (nLeft <= nRight)
	{
		nMid = (nLeft + nRight) / 2;
		if (Check(pnSum, nInputN, nInputM, nMid))
			nLeft = nMid + 1;
		else 
			nRight = nMid - 1;
	}

	printf("%d", nLeft);




Exit0:

	return 0;
}