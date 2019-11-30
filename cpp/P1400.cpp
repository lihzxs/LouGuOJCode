/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-3 18:53
//	Comment		:	OJ(P1400)
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
	int				nInputN;
	int				nInputD;
	int				nMaxIndex			= 0;
	long long		nAns				= 1;
	int*			pnSeq				= NULL;
	scanf("%d%d", &nInputN, &nInputD);
	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);

	for (int i = 1; i < nInputN; i++)
	{
		while ((pnSeq[i] - nInputD) > pnSeq[nMaxIndex] && nMaxIndex < i)
			nMaxIndex++;
		nAns *= (i - nMaxIndex) + 1;
		nAns %= 1000000009;
	}
	printf("%d", nAns);

Exit0:
	return 0;
}