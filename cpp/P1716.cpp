/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 20:47
//	Comment		:	OJ(P1716)
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
	long long*		pllSeq			= NULL;


	scanf("%d", &nInputN);
	pllSeq = (long long*)malloc(nInputN * sizeof(long long));
	
	for (int i = 0; i < nInputN; i++)
		scanf("%lld", pllSeq + i);


	sort(pllSeq, pllSeq + nInputN);

	for (int i = 0; i < nInputN / 2 ; i++)
	{
		printf("%lld\n", pllSeq[nInputN - 1 - i]);
		printf("%lld\n", pllSeq[i]);
	}
	if (nInputN % 2)
		printf("%lld\n", pllSeq[nInputN / 2]);




Exit0:

	return 0;
}