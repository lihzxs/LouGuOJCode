/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-8 16:18
//	Comment		:	OJ(P1077)
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
	int			nInputN;
	int			nInputM;
	int*		pnSeq				= NULL;
	int**		ppnDp				= NULL;
	scanf("%d%d", &nInputN, &nInputM);
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	ppnDp = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 0; i <= nInputN; i++)
	{
		ppnDp[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnDp[i], 0, (nInputM + 1) * sizeof(int));
	}
	ppnDp[0][0] = 1;

	for (int i = 1; i <= nInputN; i++)
		for (int j = 0; j <= nInputM; j++)
			for (int k = 0; k <= min(j, pnSeq[i]); k++)
				ppnDp[i][j] = (ppnDp[i][j] + ppnDp[i - 1][j - k]) % 1000007;

	printf("%d", ppnDp[nInputN][nInputM]);



Exit0:

	return 0;
}