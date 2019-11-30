/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-19 22:44
//	Comment		:	OJ(P2623)
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
	int				nInputN;
	int				nInputM;
	int*			pnBag				= NULL;
	int				nX;
	int				nA;
	int				nB;
	int				nC;
	scanf("%d%d", &nInputN, &nInputM);

	pnBag = (int*)malloc((nInputM + 1) * sizeof(int));
	memset(pnBag, 0, (nInputM + 1) * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nX);
		if (nX == 3)
		{
			scanf("%d%d", &nA, &nB);
			for (int j = nB; j <= nInputM; j++)
				pnBag[j] = max(pnBag[j], pnBag[j - nB] + nA);
		}
		if (nX == 2)
		{
			scanf("%d%d%d", &nA, &nB, &nC);
			for (int j = nInputM; j >= nB; j--)
			{
				for (int k = 1; k <= min(nC, j / nB); k++)
				{
					if (j - k * nB < 0)
						break;
					pnBag[j] = max(pnBag[j], pnBag[j - k * nB] + nA * k);
				}
			}
		}
		if (nX == 1)
		{
			scanf("%d%d", &nA, &nB);
			for (int j = nInputM; j >= 0; j--)
				for (int k = 1; k <= j; k++)
					pnBag[j] = max(pnBag[j], pnBag[j - k] + k * k * nA - nB * k);
		}
	}

	printf("%d", pnBag[nInputM]);
Exit0:

	return 0;
}