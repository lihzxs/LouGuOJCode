/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-30 19:16
//	Comment		:	OJ(P1965)
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

int MyPow(int nDown, int nUp, int nMod)
{
	int nTemp = 1;
	for (int i = 0; i < nUp; i++)
	{
		nTemp *= nDown;
		nTemp %= nMod;
	}
	return nTemp;
}

int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputK;
	int				nInputX;

	scanf("%d%d%d%d", &nInputN, &nInputM, &nInputK, &nInputX);

	cout << (nInputX % nInputN + nInputM * Mode(10, nInputK, nInputN) % nInputN) % nInputN;

Exit0:
	return 0;
}