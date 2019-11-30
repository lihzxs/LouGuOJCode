/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-19 19:24
//	Comment		:	OJ(P4057)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		20000
#define	EPS         0.0001
#define ERROR_ID    0

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

unsigned long long CalcGCD(unsigned long long a, unsigned long long b)
{
	if (a % b == 0)
		return b;
	return CalcGCD(b, a % b);
}


int main(int argc, char* argv[])
{
	unsigned long long			nInputA;
	unsigned long long			nInputB;
	unsigned long long			nInputC;
	unsigned long long			nGCD;

	scanf("%llu%llu%llu", &nInputA, &nInputB, &nInputC);

	nInputA = nInputA * nInputB / CalcGCD(nInputA, nInputB);
	nInputA = nInputA * nInputC / CalcGCD(nInputA, nInputC);

	printf("%llu", nInputA);

Exit0:

	return 0;
}



