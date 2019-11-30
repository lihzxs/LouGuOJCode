/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-19 21:25
//	Comment		:	OJ(P1806)
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


int main(int argc, char* argv[])
{
	int					nInputN;
	long long**			ppnDp				= NULL;
	long long			nAns				= 0;
	scanf("%d", &nInputN);

	ppnDp = (long long**)malloc((nInputN + 1) * sizeof(long long*));

	for (int i = 0; i <= nInputN; i++)
	{
		ppnDp[i] = (long long*)malloc((nInputN + 1) * sizeof(long long));
		memset(ppnDp[i], 0, (nInputN + 1) * sizeof(long long));
		ppnDp[i][i] = 1;
	}

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j < i; j++)
			for (int k = 1; k < j && j + k <= i; k++)
				ppnDp[i][j] += ppnDp[i - j][k];
	}

	for (int i = 1; i < nInputN; i++)
		nAns += ppnDp[nInputN][i];

	printf("%lld", nAns);



Exit0:

	return 0;
}