/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 22:27
//	Comment		:	OJ(P1011)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int*				pnSeqFirst			= NULL;
	int*				pnSeqSecond			= NULL;
	int					nInputA;
	int					nInputN;
	int					nInputM;
	int					nInputX;
	int					nTemp;

	scanf("%d%d%d%d", &nInputA, &nInputN, &nInputM, &nInputX);
	pnSeqFirst = (int*)malloc(nInputN * sizeof(int));
	pnSeqSecond = (int*)malloc(nInputN * sizeof(int));
	pnSeqFirst[0] = 0;
	pnSeqFirst[1] = 1;
	pnSeqFirst[2] = 1;
	pnSeqFirst[3] = 2;

	pnSeqSecond[0] = 0;
	pnSeqSecond[1] = 0;
	pnSeqSecond[2] = 0;
	pnSeqSecond[3] = 0;


	for (int i = 4; i < nInputN; i++)
	{
		pnSeqFirst[i] = pnSeqFirst[i - 2] + pnSeqFirst[i - 1] - 1;
		pnSeqSecond[i] = pnSeqSecond[i - 2] + pnSeqSecond[i - 1] + 1;
	}
	nTemp = (nInputM - nInputA * pnSeqFirst[nInputN - 1]) / 
		pnSeqSecond[nInputN - 1];

	printf("%d", nInputA * pnSeqFirst[nInputX] + nTemp * pnSeqSecond[nInputX]);



Exit0:

	return 0;
}