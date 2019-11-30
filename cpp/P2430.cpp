/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-25 13:35
//	Comment		:	OJ(P2430)
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

	int				nInputWKY;
	int				nInputLJ;
	int				nInputM;
	int				nInputN;
	int				nInputP;
	int				nInputW;
	int*			pnSeqTime			= NULL;
	int*			pnBagFrom			= NULL;

	scanf("%d%d", &nInputWKY, &nInputLJ);

	scanf("%d%d", &nInputM, &nInputN);

	pnSeqTime = (int*)malloc((nInputN + 1) * sizeof(int));
	pnBagFrom = (int*)malloc(5001 * sizeof(int));
	memset(pnBagFrom, 0, 5001 * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", pnSeqTime + i);
		pnSeqTime[i] *= nInputLJ / nInputWKY;
	}

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nInputP, &nInputW);
		for (int j = 5000; j >= 0; j--)
		{
			if (pnSeqTime[nInputP] <= j)
				pnBagFrom[j] = max(pnBagFrom[j], 
					pnBagFrom[j - pnSeqTime[nInputP]] + nInputW);
		}
	}

	scanf("%d", &nInputP);
	printf("%d", pnBagFrom[nInputP]);











Exit0:

	return 0;
}