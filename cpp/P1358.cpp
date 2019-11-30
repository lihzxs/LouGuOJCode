/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-16 14:59
//	Comment		:	OJ(P1358)
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


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int**			ppnDp			= NULL;
	int				nTemp;
	int				nSum			= 1;

	scanf("%d%d", &nInputN, &nInputM);

	ppnDp = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 0; i <= nInputN; i++)
		ppnDp[i] = (int*)malloc(101 * sizeof(int));
	memset(ppnDp[0], 0, 101 * sizeof(int));

	for (int i = 0; i <= nInputN; i++)
	{
		ppnDp[i][0] = 1;
		if (i < 101)
			ppnDp[i][i] = 1;
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= 100; j++)
			ppnDp[i][j] = (ppnDp[i - 1][j] + ppnDp[i - 1][j - 1]) % 10007;

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d", &nTemp);
		nSum *= ppnDp[nInputN][nTemp];
		nSum %= 10007;
		nInputN -= nTemp;
	}

	printf("%d", nSum);

Exit0:

	return 0;
}