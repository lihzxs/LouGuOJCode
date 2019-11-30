/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 15:23
//	Comment		:	OJ(P2725)
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
#include <list>
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
	int					nInputK;
	int					nInputN;
	int*				pnSeq				= NULL;
	int*				pnBagFrom			= NULL;

	scanf("%d%d", &nInputK, &nInputN);
	pnBagFrom = (int*)malloc(2000000 * sizeof(int));
	for (int i = 1; i < 2000000; i++)
		pnBagFrom[i] = 2000000000;
	pnBagFrom[0] = 0;
	pnSeq = (int*)malloc(nInputN * sizeof(int));
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);


	for (int i = 0; i < nInputN; i++)
	{
		for (int j = pnSeq[i]; j < 2000000; j++)
			if (pnBagFrom[j - pnSeq[i]] + 1 <= nInputK)
				pnBagFrom[j] = min(pnBagFrom[j], 
					pnBagFrom[j - pnSeq[i]] + 1);
	}
	for (int i = 1; i < 2000000; i++)
		if (pnBagFrom[i] == 2000000000)
		{
			printf("%d", i - 1);
			return 0;
		}



Exit0:

	return 0;
}