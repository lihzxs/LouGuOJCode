/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-27 20:25
//	Comment		:	OJ(P1990)
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
#include <list>
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
	int*			pnSeq			= NULL;

	scanf("%d", &nInputN);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));

	pnSeq[1] = 1;
	pnSeq[2] = 2;
	pnSeq[3] = 5;
	pnSeq[4] = 11;

	for (int i = 5; i <= nInputN; i++)
		pnSeq[i] = (pnSeq[i - 1] * 2 + pnSeq[i - 3]) % 10000;


	printf("%d", pnSeq[nInputN]);

Exit0:

	return 0;
}