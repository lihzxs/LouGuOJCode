/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-5 15:59
//	Comment		:	OJ(P2719)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;






int main(int argc, char* argv[])
{
	int				nInputN;
	double**		ppfDP				= NULL;

	scanf("%d", &nInputN);
	nInputN = nInputN / 2;
	
	ppfDP = (double**)malloc((nInputN + 1) * sizeof(double*));

	for (int i = 0; i <= nInputN; i++)
	{
		ppfDP[i] = (double*)malloc((nInputN + 1) * sizeof(double));
		memset(ppfDP[i], 0, (nInputN + 1) * sizeof(double));
	}
		

	for (int i = 2; i <= nInputN; i++)
		ppfDP[0][i] = ppfDP[i][0] = 1;


	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
			ppfDP[i][j] = (ppfDP[i - 1][j] + ppfDP[i][j - 1]) * 0.5;


	printf("%.4f\n", ppfDP[nInputN][nInputN]);



Exit0:
	return 0;
}