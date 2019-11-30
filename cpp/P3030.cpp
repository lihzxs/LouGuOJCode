/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-21 01:09
//	Comment		:	OJ(P3030)
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

int					pnSeq[15];
int					pnDp[15][10005];
int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;


	scanf("%d%d", &nInputN, &nInputM);

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	for (int i = 1; i <= nInputM; i++)
		pnDp[0][i] = 1000000000;


	for (int i = 1; i <= nInputN; i++)
		for (int j = 0; j <= nInputM; j++)
		{
			pnDp[i][j] = 1000000000;
			for (int k = 1; k * k <= j; k++)
			{
				if (pnDp[i - 1][j - k * k] != 1000000000)
					pnDp[i][j] = min(pnDp[i][j],
						pnDp[i - 1][j - k * k] + abs(pnSeq[i] - k) * abs(pnSeq[i] - k));
			}
		}

	if (pnDp[nInputN][nInputM] == 1000000000)
		printf("-1\n");
	else
		printf("%d\n", pnDp[nInputN][nInputM]);
Exit0:

	return 0;
}