/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-4 23:17
//	Comment		:	OJ(P2663)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnSeq				= NULL;
	int				nSum				= 0;
	int*			pnBagForm			= NULL;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		nSum += pnSeq[i];
	}

	nSum /= 2;

	pnBagForm = (int*)malloc((nSum + 1) * sizeof(int));
	memset(pnBagForm, 0, (nSum + 1) * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		for (int j = nSum; j >= pnSeq[i]; j--)
			pnBagForm[j] = max(pnBagForm[j],
				pnBagForm[j - pnSeq[i]] + pnSeq[i]);
	}

	printf("%d", pnBagForm[nSum]);
		





Exit0:
	return 0;
}