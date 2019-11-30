/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-29 22:18
//	Comment		:	OJ(P3662)
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
#define	MAXNUM		201
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputK;
	int			nInputB;
	int			nTemp;
	int*		pnFlag			= NULL;
	int*		pnSum			= NULL;
	int			nAns;

	scanf("%d%d%d", &nInputN, &nInputK, &nInputB);
	nAns = nInputN;
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSum = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	memset(pnSum, 0, (nInputN + 1) * sizeof(int));

	while (nInputB--)
	{
		scanf("%d", &nTemp);
		pnFlag[nTemp] = 1;
	}

	for (int i = 1; i <= nInputN; i++)
		pnSum[i] = pnSum[i - 1] + pnFlag[i];

	for (int i = nInputK; i <= nInputN; i++)
		nAns = min(nAns, pnSum[i] - pnSum[i - nInputK]);

	printf("%d", nAns);
Exit0:

	return 0;
}