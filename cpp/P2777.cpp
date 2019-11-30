/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-29 15:33
//	Comment		:	OJ(P2777)
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
#define	MAXNUM		201
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int						nInputN;
	int*					pnSeq			= NULL;
	int						nAns			= 0;
	int						nFlag			= 1;
	int						nMax;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);

	for (int i = 0; i < nInputN; i++)
		nMax = max(nMax, pnSeq[i] + nInputN - i);

	for (int i = nInputN - 1; i >= 0; i--)
		if (pnSeq[i] + nInputN >= nMax)
			nAns++;
		else
			break;

	printf("%d", nAns);



Exit0:

	return 0;
}