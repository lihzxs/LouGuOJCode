/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-13 23:11
//	Comment		:	OJ(P2699)
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

int main(int argc, char* argv[])
{
	long long			nL;
	long long			nR;
	long long			nW;
	long long			nFlag			= 0;
	long long			nT				= 1;


	scanf("%lld%lld%lld", &nL, &nR, &nW);
	if (nL == 1)
	{
		nFlag = 1;
		printf("1 ");
	}
	if (nW > 1)
	{
		while (nT < nL / nW || (nT == nL / nW && (nL % nW)))
			nT *= nW;
		while (nT <= nR / nW)
		{
			nT *= nW;
			nFlag = 1;
			printf("%lld ", nT);
		}
	}
	if (!nFlag)
		printf("-1");

		


Exit0:

	return 0;
}