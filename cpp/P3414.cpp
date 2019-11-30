/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-8 16:26
//	Comment		:	OJ(P3414)
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

long long Mode(long long a, long long b, long long mode)
{
	int sum = 1;
	a = a % mode;

	while (b > 0) {
		if (b % 2 == 1)		//判断是否是奇数，是奇数的话将多出来的数事先乘如sum
			sum = (sum * a) % mode;

		b /= 2;
		a = (a * a) % mode;// 不断的两两合并再取模，减小a和b的规模
	}
	return sum;
}

int main(int argc, char* argv[])
{
	long long			llInputN;
	scanf("%lld", &llInputN);

	printf("%lld\n", Mode(2, llInputN - 1, 6662333l));



Exit0:

	return 0;
}