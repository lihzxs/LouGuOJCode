
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-22 00:34
//	Comment		:	OJ(P5535)
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
#include <float.h>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

bool IsPrime(long long nNum)
{
	if (nNum == 1)
		return 0;
	if (nNum == 2)
		return 1;
	for (int i = 2; i <= sqrt(nNum); i++)
		if (nNum % i == 0)
			return 0;
	return 1;
}


int main(int argc, char* argv[])
{
	long long		llInputN;
	long long		llInputK;

	scanf("%lld%lld", &llInputN, &llInputK);

	if (IsPrime(llInputK + 1) && 2 * llInputK >= llInputN)
		printf("1");
	else
		printf("2");



Exit0:

	return 0;
}