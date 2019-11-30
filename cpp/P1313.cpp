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

long long dp[1005][1005];

int main(int argc, char* argv[])
{
	int				nA;
	int				nB;
	int				nK;
	int				nN;
	int				nM;

	cin >> nA >> nB >> nK >> nN >> nM;

	dp[0][0] = 1;

	for (int i = 0; i <= nN; i++)
		for (int j = 0; j <= nM; j++)
		{
			if (i == 0 && j == 0)
				continue;

			if (i > 0)
				dp[i][j] = (dp[i][j] + dp[i - 1][j] * nA) % 10007;
			if (j > 0)
				dp[i][j] = (dp[i][j] + dp[i][j - 1] * nB) % 10007;
		}

	printf("%lld", dp[nN][nM]);
Exit0:

	return 0;
}