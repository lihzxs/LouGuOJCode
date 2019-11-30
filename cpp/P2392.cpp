/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-9 23:20
//	Comment		:	OJ(P2392)
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

using namespace std;
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int*			pnSeq		= NULL;
	int*			pnBagForm	= NULL;
	int*			pnInput		= NULL;
	int				nSum		= 0;
	int				nAns		= 0;
	int				nTemp;
	pnSeq = (int*)malloc(4 * sizeof(int));

	pnBagForm = (int*)malloc(1300 * sizeof(int));
	pnInput = (int*)malloc(21 * sizeof(int));
	memset(pnBagForm, 0, 1300 * sizeof(int));
	for (int i = 0; i < 4; i++)
		scanf("%d", pnSeq + i);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < pnSeq[i]; j++)
		{
			scanf("%d", pnInput + j);
			nSum += pnInput[j];
		}
		for (int j = 0; j < pnSeq[i]; j++)
		{
			for (int k = nSum / 2; k >= pnInput[j]; k--)
			{
				pnBagForm[k] = max(pnBagForm[k],
					pnBagForm[k - pnInput[j]] + pnInput[j]);
			}
		}
		nAns += nSum - pnBagForm[nSum / 2];

		nSum = 0;
		memset(pnBagForm, 0, 1300 * sizeof(int));
	}

	printf("%d", nAns);



Exit0:

	return 0;
}