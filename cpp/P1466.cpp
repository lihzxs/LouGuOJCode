/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-5 15:04
//	Comment		:	OJ(P1466)
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
	int				nTemp;
	long long*		pllSeq			= NULL;

	scanf("%d", &nInputN);
	nTemp = nInputN;
	nInputN = (nInputN + 1) * nInputN / 2;
	if (nInputN % 2 == 0)
		nInputN /= 2;
	else
	{
		printf("0");
		return 0;
	}
	pllSeq = (long long*)malloc((nInputN + 1) * sizeof(long long));
	memset(pllSeq, 0, (nInputN + 1) * sizeof(long long));

	pllSeq[0] = 1;

	for (int i = 1; i <= nTemp; i++)
		for (int j = nInputN; j >= i; j--)
			pllSeq[j] = pllSeq[j] + pllSeq[j - i];

	printf("%lld\n", pllSeq[nInputN] / 2);


Exit0:
	return 0;
}