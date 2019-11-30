/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 17:34
//	Comment		:	OJ(P2800)
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
	int				nInputN;
	int*			pnSeq				= NULL;
	int*			pnDP				= NULL;

	scanf("%d", &nInputN);

	pnSeq = (int*)malloc((nInputN + 2) * sizeof(int));
	pnDP = (int*)malloc((nInputN + 2) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);
	pnDP[0] = 0;
	pnSeq[nInputN + 1] = 0;
	for (int i = 1; i <= nInputN + 1; i++)
	{
		pnDP[i] = pnDP[i - 1] + pnSeq[i];
		if (i - 2 >= 0)
			pnDP[i] = min(pnDP[i], pnDP[i - 2] + pnSeq[i]);
		if (i - 3 >= 0)
			pnDP[i] = min(pnDP[i], pnDP[i - 3] + pnSeq[i]);
	}
	printf("%d", pnDP[nInputN + 1]);



Exit0:

	return 0;
}