/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-5 17:34
//	Comment		:	OJ(P1226)
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
#include <sstream>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int Mode(int a, int b, int mode)
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
	int				nInputB;
	int				nInputP;
	int				nInputK;

	scanf("%d%d%d", &nInputB, &nInputP, &nInputK);

	if (nInputP == 0)
		if (nInputK == 1)
			printf("%d^%d mod %d=0\n", nInputB, nInputP, nInputK);
		else
			printf("%d^%d mod %d=1\n", nInputB, nInputP, nInputK);
	else
		printf("%d^%d mod %d=%d\n", nInputB, nInputP, nInputK,
			Mode(nInputB, nInputP, nInputK));


Exit0:
	return 0;
}