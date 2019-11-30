/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-24 16:12
//	Comment		:	OJ(P5104)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <list>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
const int MODNUM = 1e9 + 7;


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

long long FastPow(long long a, long long b, long long mode)
{
	long long sum = 1;
	while (b)
	{
		if (b & 1)
		{
			sum *= a;
			sum %= mode;
		}
		a *= a;
		a %= mode;
		b >>= 1;
	}
	return sum;
}

int main(int argc, char* argv[])
{

	long long				nInputW;
	long long				nInputN;
	long long				nInputK;
	long long		llAns;
	scanf("%lld%lld%lld", &nInputW, &nInputN, &nInputK);
	llAns = FastPow(2, MODNUM - 2, MODNUM);
	llAns = nInputW * FastPow(llAns, nInputK, MODNUM) % MODNUM;
	cout << llAns;

Exit0:

	return 0;
}