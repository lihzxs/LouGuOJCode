/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-22 22:56
//	Comment		:	OJ(P2626)
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
#define	MAXNUM		100000
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;





int main(int argc, char* argv[])
{
	long long			nInputN;
	long long*			pnSeq				= NULL;
	long long			llModNum			= pow(2, 31);

	scanf("%lld", &nInputN);
	pnSeq = (long long*)malloc((nInputN + 1) * sizeof(long long));

	pnSeq[1] = 1;
	pnSeq[2] = 1;

	for (int i = 3; i <= nInputN; i++)
		pnSeq[i] = (pnSeq[i - 1] + pnSeq[i - 2]) % llModNum;


	printf("%d=", pnSeq[nInputN]);
	
	for (long long i = 2; i * i <= pnSeq[nInputN]; i++)
	{
		if (pnSeq[nInputN] % i == 0 && i != pnSeq[nInputN])
		{
			printf("%d*", i);
			pnSeq[nInputN] /= i;
			i--;
		}
	}
	printf("%d", pnSeq[nInputN]);




















Exit0:

	return 0;
}