/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-8 1:12
//	Comment		:	OJ(P1586)
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
	int**				pnSeq			= NULL;
	int					nInputT;
	int					nInputN;
	int					nSum = 0;
	pnSeq = (int**)malloc(32769 * sizeof(int*));

	for (int i = 0; i < 32769; i++)
	{
		pnSeq[i] = (int*)malloc(5 * sizeof(int));
		memset(pnSeq[i], 0, 5 * sizeof(int));
	}
	pnSeq[0][0] = 1;

	for (int i = 1; i * i < 32769; i++)
		for (int j = i * i; j < 32769; j++)
			for (int k = 1; k < 5; k++)
				pnSeq[j][k] += pnSeq[j - i * i][k - 1];


	scanf("%d", &nInputT);
	while (nInputT--)
	{
		nSum = 0;
		scanf("%d", &nInputN);
		for (int i = 1; i <= 4; i++)
			nSum += pnSeq[nInputN][i];
		printf("%d\n", nSum);
	}
Exit0:

	return 0;
}