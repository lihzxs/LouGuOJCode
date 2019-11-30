/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 00:14
//	Comment		:	OJ(P1455)
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

int Fin(int* pnSet, int nNum)
{
	if (pnSet[nNum] == nNum)
		return pnSet[nNum];
	else
		return pnSet[nNum] =
		Fin(pnSet, pnSet[nNum]);
}

int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputW;
	int*			pnSet				= NULL;
	int*			pnPrice				= NULL;
	int*			pnVal				= NULL;
	int*			pnBag				= NULL;
	int				nU;
	int				nV;

	scanf("%d%d%d", &nInputN, &nInputM, &nInputW);

	pnSet = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnSet, 0, (nInputN + 1) * sizeof(int));
	pnPrice = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnPrice, 0, (nInputN + 1) * sizeof(int));
	pnVal = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnVal, 0, (nInputN + 1) * sizeof(int));
	pnBag = (int*)malloc((nInputW + 1) * sizeof(int));
	memset(pnBag, 0, (nInputW + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		pnSet[i] = i;


	for (int i = 1; i <= nInputN; i++)
		scanf("%d%d", pnPrice + i, pnVal + i);

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nU, &nV);
		pnSet[Fin(pnSet, nU)] = Fin(pnSet, nV);
	}

	for (int i = 1; i <= nInputN; i++)
		if (pnSet[i] != i)
		{
			pnPrice[Fin(pnSet, i)] += pnPrice[i];
			pnVal[Fin(pnSet, i)] += pnVal[i];
			pnPrice[i] = 0;
			pnVal[i] = 0;
		}

	for (int i = 1; i <= nInputN; i++)
		for (int k = nInputW; k >= pnPrice[i]; k--)
			pnBag[k] = max(pnBag[k], pnBag[k - pnPrice[i]] + pnVal[i]);

	printf("%d", pnBag[nInputW]);

		







Exit0:

	return 0;
}