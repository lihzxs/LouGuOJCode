/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-23 23:45
//	Comment		:	OJ(P1029)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

long long CalcGCD(long long a, long long b)
{
	if (a%b == 0)
		return b;
	return CalcGCD(b, a%b);
}





int main(int argc, char* argv[])
{
	long long				llInputP;
	long long				llInputQ;
	int						nAns			= 0;
	scanf("%lld%lld", &llInputP, &llInputQ);

	for (long long i = llInputP; i <= llInputQ; i++)
		if ((llInputP * llInputQ) % i == 0 && CalcGCD (i, (llInputP * llInputQ) / i) == llInputP)
			nAns++;

			

	printf("%d", nAns);
Exit0:

	return 0;
}