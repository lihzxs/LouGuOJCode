/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-27 00:05
//	Comment		:	OJ(P1461)
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

int	CountOne(int nN)
{
	int		nCount = 0;
	while (nN)
	{
		if (nN % 2)
			nCount++;
		nN /= 2;
	}
	return nCount;
}

int main(int argc, char* argv[])
{

	int				nInputN;
	int				nInputB;
	int				nInputD;
	int*			pnAns		= NULL;
	int				nCount		= 0;
	int				nTemp;
	scanf("%d%d%d", &nInputN, &nInputB, &nInputD);
	pnAns = (int*)malloc((nInputN + 1) * sizeof(int));
	pnAns[0] = 0;
	nCount = 1;
	nTemp = 1;
	while (nCount < nInputN)
	{
		int j;
		for (j = nCount; j >= 0 && CountOne(pnAns[j] ^ nTemp) >= nInputD; j--);
		if (j == -1)
			pnAns[nCount++] = nTemp;
		nTemp++;
	}

	for (int i = 1; i <= nCount; i++)
	{
		
		printf("%d ", pnAns[i - 1]);
		if (i % 10 == 0)
			printf("\n");
	}
Exit0:

	return 0;
}