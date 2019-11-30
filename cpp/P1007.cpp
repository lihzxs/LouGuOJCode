/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-26 21:45
//	Comment		:	OJ(P1007)
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
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;





int main(int argc, char* argv[])
{
	int					nInputL;
	int					nInputN;
	int					nMax			= 0;
	int					nMin			= 0;
	int*				pnSeq			= NULL;

	scanf("%d%d", &nInputL, &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	if (nInputN == 0)
	{
		printf("%d %d", nMin, nMax);
		return 0;
	}

	sort(pnSeq, pnSeq + nInputN);
	nMax = max(pnSeq[0], nInputL + 1 - pnSeq[0]);
	nMin = min(pnSeq[0], nInputL + 1 - pnSeq[0]);

	for (int i = 1; i < nInputN; i++)
	{
		if (nMax < max(pnSeq[i], nInputL + 1 - pnSeq[i]))
			nMax = max(pnSeq[i], nInputL + 1 - pnSeq[i]);
		if (nMin < min(pnSeq[i], nInputL + 1 - pnSeq[i]))
			nMin = min(pnSeq[i], nInputL + 1 - pnSeq[i]);
	}

	printf("%d %d", nMin, nMax);


		




Exit0:

	return 0;
}