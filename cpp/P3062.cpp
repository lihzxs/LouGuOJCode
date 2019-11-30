/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-22 20:18
//	Comment		:	OJ(P3062)
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
#define MODNUM		2e64


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputA;
	int				nInputB;
	int				nInputN;
	double			fTemp;
	int				nR;
	int*			pnSeq				= NULL;
	int				nIndex;
	double			fAns = 0;

	scanf("%d%d%d", &nInputN, &nInputA, &nInputB);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq + 1, pnSeq + 1 + nInputN);

	nIndex = 1;
	while (nIndex <= nInputN)
	{
		fTemp = nInputA;
		nR = nIndex + 1;
		while (nR <= nInputN &&
			(pnSeq[nR] - pnSeq[nIndex]) *  nInputB * 1.0 / 2 + nInputA <= fTemp + nInputA)
		{
			fTemp = (pnSeq[nR] - pnSeq[nIndex]) *  nInputB * 1.0 / 2 + nInputA;
			nR++;
		}
		fAns += fTemp;
		nIndex = nR;
	}

    if (fAns - int(fAns) < 1e-2)
		printf("%d", int(fAns));
	else
		printf("%.1f", fAns);


Exit0:

	return 0;
}