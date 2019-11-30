/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-20 21:53
//	Comment		:	OJ(P2871)
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
#define	MAXNUM		7010
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int			nC;
	int			nW;
	int*		pnBagFrom		= NULL;

	scanf("%d%d", &nInputN, &nInputM);

	pnBagFrom = (int*)malloc((nInputM + 1) * sizeof(int));
	memset(pnBagFrom, 0, (nInputM + 1) * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nC, &nW);

		for (int j = nInputM; j >= 0; j--)
			if (nC <= j)
				pnBagFrom[j] = max(pnBagFrom[j], pnBagFrom[j - nC] + nW);

	}
	printf("%d", pnBagFrom[nInputM]);


Exit0:

	return 0;
}