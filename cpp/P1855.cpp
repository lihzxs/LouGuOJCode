/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-15 0:09
//	Comment		:	OJ(P1855)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputT;
	int				nMoney;
	int				nTime;
	int**			pnBagFrom				= NULL;
	scanf("%d%d%d", &nInputN, &nInputM, &nInputT);

	pnBagFrom = (int**)malloc((nInputM + 1) * sizeof(int*));

	for (int i = 0; i <= nInputM; i++)
	{
		pnBagFrom[i] = (int*)malloc((nInputT + 1) * sizeof(int));
		memset(pnBagFrom[i], 0, (nInputT + 1) * sizeof(int));
	}
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nMoney, &nTime);
		for (int j = nInputM; j >= nMoney; j--)
			for (int k = nInputT; k >= nTime; k--)
				pnBagFrom[j][k] = max(pnBagFrom[j][k],
					pnBagFrom[j - nMoney][k - nTime] + 1);
	}

	printf("%d", pnBagFrom[nInputM][nInputT]);



Exit0:

	return 0;
}