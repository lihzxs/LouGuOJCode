/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-4 21:57
//	Comment		:	OJ(P2918)
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
	int				nInputH;
	int				nPrice;
	int				nH;
	long long		nMin					= INT64_MAX;
	long long*			pnBagFrom			= NULL;
	
	scanf("%d%d", &nInputN, &nInputH);

	pnBagFrom = (long long*)malloc((nInputH + 5005) * sizeof(long long));
	memset(pnBagFrom, 1, (nInputH + 5005) * sizeof(long long));

	pnBagFrom[0] = 0;
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nH, &nPrice);
		for (int j = nH; j <= nInputH + 5000; j++)
			pnBagFrom[j] = min(pnBagFrom[j], pnBagFrom[j - nH] + nPrice);
	}
	for (int i = nInputH; i <= nInputH + 5000; i++)
		nMin = min(nMin, pnBagFrom[i]);
	printf("%lld", nMin);




Exit0:
	return 0;
}