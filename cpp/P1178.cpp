/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-22 17:20
//	Comment		:	OJ(P1178)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;






int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputMonth;
	int			nInputDay;
	int			nMax					= 0;
	int*		pnSeq					= NULL;
	int*		pnCountDay				= NULL;

	scanf("%d", &nInputN);
	pnSeq = (int*)malloc(nInputN * sizeof(int));

	pnCountDay = (int*)malloc(13 * sizeof(int));
	pnCountDay[1] = 0;
	pnCountDay[2] = 31;
	pnCountDay[3] = 60;
	pnCountDay[4] = 91;
	pnCountDay[5] = 121;
	pnCountDay[6] = 152;
	pnCountDay[7] = 182;
	pnCountDay[8] = 213;
	pnCountDay[9] = 244;
	pnCountDay[10] = 274;
	pnCountDay[11] = 305;
	pnCountDay[12] = 335;

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nInputMonth, &nInputDay);
		pnSeq[i] = pnCountDay[nInputMonth] + nInputDay;
	}

	sort(pnSeq, pnSeq + nInputN);

	for (int i = 1; i < nInputN; i++)
	{
		if (nMax < pnSeq[i] - pnSeq[i - 1])
			nMax = pnSeq[i] - pnSeq[i - 1];
	}
	if (nMax < pnSeq[0])
		nMax = pnSeq[0];

	if (nMax < 367 - pnSeq[nInputN - 1])
		nMax = 367 - pnSeq[nInputN - 1];
	nMax--;
	if (nInputN == 0)
		nMax = 366;
	printf("%.0f", 24 * 3600.0 * nMax / 366.0);







Exit0:

	return 0;
}