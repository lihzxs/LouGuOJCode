
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-22 21:51
//	Comment		:	OJ(P5159)
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

long long Mode(long long a, long long b, long long mode)
{
	long long sum = 1;
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
	int					nInputT;
	int					nInputN;
	int					nInputM;
	long long			llAns;

	scanf("%d", &nInputT);


	while (nInputT--)
	{
		scanf("%d%d", &nInputN, &nInputM);
		llAns = Mode(2, nInputN - 1, 998244353ll);
		llAns = Mode(llAns, nInputM - 1, 998244353ll);
		printf("%lld\n", llAns);
	}




Exit0:

	return 0;
}