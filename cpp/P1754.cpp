/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-29 21:27
//	Comment		:	OJ(P1754)
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
	int				nInputN;
	long long**			ppnDp				= NULL;

	scanf("%d", &nInputN);
	ppnDp = (long long**)malloc((nInputN + 1) * sizeof(long long*));

	for (int i = 0; i <= nInputN; i++)
	{
		ppnDp[i] = (long long*)malloc((nInputN + 1) * sizeof(long long));
		memset(ppnDp[i], 0, (nInputN + 1) * sizeof(long long));
		ppnDp[i][0] = 1;
	}


	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= i; j++)
			ppnDp[i][j] = ppnDp[i - 1][j] + ppnDp[i][j - 1];
	}

	printf("%lld", ppnDp[nInputN][nInputN]);


Exit0:

	return 0;
}