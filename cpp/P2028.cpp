/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-20 00:21
//	Comment		:	OJ(P4328)
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
unsigned long long	dp[10001][10001];
int main(int argc, char* argv[])
{
	long long			nInputN;
	long long			nInputM;
	long long			nInputP;

	cin >> nInputN >> nInputM >> nInputP;

	dp[1][1] = 1;

	for (int i = 1; i <= nInputN; i++)
	{
		dp[i][1] = 1;
		for (int j = 1; j <= nInputM; j++)
		{
			if (i == 1 && j == 1)
				continue;
			dp[i][j] = ((j % nInputP) * dp[i - 1][j] % nInputP + dp[i - 1][j - 1] % nInputP) % nInputP;
		}
	}

	printf("%llu", dp[nInputN][nInputM]);
Exit0:

	return 0;
}