/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 23:34
//	Comment		:	OJ(P2807)
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
	int					nInputT;
	int					nInputN;
	int					nAns			= 0;
	int*				pnSeq			= NULL;

	scanf("%d", &nInputT);
	pnSeq = (int*)malloc(501 * sizeof(int));
	pnSeq[0] = 0;
	for (int i = 1; i <= 500; i++)
		pnSeq[i] = pnSeq[i - 1] + i;
	for (int i = 0; i < nInputT; i++)
	{
		scanf("%d", &nInputN);
		for (int j = 1; j <= nInputN; j++)
			nAns += pnSeq[nInputN - j + 1];

		for (int j = 1; j <= nInputN / 2; j++)
			nAns += pnSeq[nInputN - j * 2 + 1];
		
		printf("%d\n", nAns);

		nAns = 0;
	}













Exit0:
	return 0;
}