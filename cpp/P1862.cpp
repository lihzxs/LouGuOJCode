/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 21:46
//	Comment		:	OJ(P1862)
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
	int				nInputN;
	int				nInputX;
	int				nAns		= 0;
	int*			pnSeq		= NULL;

	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", &nInputX, pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);

	for (int i = 0; i < nInputN; i++)
		nAns += abs(pnSeq[i] - pnSeq[nInputN / 2]);

	printf("%d", nAns);





Exit0:

	return 0;
}