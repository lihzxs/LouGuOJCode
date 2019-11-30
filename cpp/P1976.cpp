/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-13 00:19
//	Comment		:	OJ(P1976)
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
#include <list>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int					nInputN;
	long long*			pllAns					= NULL;

	scanf("%d", &nInputN);
	pllAns = (long long*)malloc((nInputN + 1) * sizeof(long long));
	memset(pllAns, 0, (nInputN + 1) * sizeof(long long));
	pllAns[0] = 1;
	pllAns[1] = 1;
	for (int i = 2; i <= nInputN; i++)
		for (int j = 0; j <= i - 1; j++)
			pllAns[i] = (pllAns[j] * pllAns[i - j - 1] % MODNUM +
				pllAns[i]) % MODNUM;

	printf("%lld", pllAns[nInputN]);



Exit0:

	return 0;
}