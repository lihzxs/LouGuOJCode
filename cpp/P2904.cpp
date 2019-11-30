/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-14 00:16
//	Comment		:	OJ(P2904)
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
	int				nN;
	int				nM;
	int*			pnSum					= NULL;
	int*			pnBagFrom				= NULL;
	int				nTemp;

	scanf("%d%d", &nN, &nM);

	pnSum = (int*)malloc((nN + 1) * sizeof(int));
	pnBagFrom = (int*)malloc((nN + 1) * sizeof(int));
	memset(pnSum, 0, (nN + 1) * sizeof(int));
	memset(pnBagFrom, 0, (nN + 1) * sizeof(int));

	for (int i = 1; i <= nN; i++)
	{
		pnBagFrom[i] = 1000000000;
		scanf("%d", &nTemp);
		pnSum[i] = pnSum[i - 1] + nTemp;
	}
	for (int i = 1; i <= nN; i++)
		pnSum[i] += 2 * nM;


	for (int i = 1; i <= nN; i++)
		for (int j = i; j <= nN; j++)
			pnBagFrom[j] = min(pnBagFrom[j], pnBagFrom[j - i] + pnSum[i]);
		

	printf("%d", pnBagFrom[nN] - nM);


Exit0:

	return 0;
}