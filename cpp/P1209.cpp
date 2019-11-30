/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-18 23:21
//	Comment		:	OJ(P1209)
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
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int					nInputM;
	int					nInputS;
	int					nInputC;
	int*				pnSeq					= NULL;
	int					nAns;

	scanf("%d%d%d", &nInputM, &nInputS, &nInputC);

	pnSeq = (int*)malloc(nInputC * sizeof(int));

	for (int i = 0; i < nInputC; i++)
		scanf("%d", pnSeq + i);
	if (nInputM >= nInputC)
	{
		printf("%d", nInputC);
		return 0;
	}
	sort(pnSeq, pnSeq + nInputC);
	nAns = pnSeq[nInputC - 1] - pnSeq[0] + 1;
	for (int i = 1; i < nInputC; i++)
		pnSeq[i - 1] = pnSeq[i] - pnSeq[i - 1];

	sort(pnSeq, pnSeq + nInputC - 1);

	for (int i = nInputC - 2; i > nInputC - 1 - nInputM; i--)
		nAns -= pnSeq[i] - 1;

	printf("%d", nAns);


Exit0:

	return 0;
}