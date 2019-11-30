/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 23:47
//	Comment		:	OJ(P1960)
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


int main(int argc, char* argv[])
{
	int			nS;
	int			nN;
	int			nD;
	int*		pnBag			= NULL;
	int*		nW				= NULL;
	int*		nC				= NULL;
	scanf("%d%d%d", &nS, &nN, &nD);
	pnBag = (int*)malloc(10000000 * sizeof(int));
	memset(pnBag, 0, 10000000 * sizeof(int));
	nW = (int*)malloc((nD + 1) * sizeof(int));
	nC = (int*)malloc((nD + 1) * sizeof(int));

	for (int i = 1; i <= nD; i++)
		scanf("%d%d", nW + i, nC + i);

	for (int k = 1; k <= nN; k++)
	{
		for (int i = 1; i <= nD; i++)
			for (int j = nW[i]; j <= nS; j++)
				pnBag[j] = max(pnBag[j], pnBag[j - nW[i]] + nC[i]);

		nS += pnBag[nS];
	}

	printf("%d", nS);


Exit0:
	return 0;
}