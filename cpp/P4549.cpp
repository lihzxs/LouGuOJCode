/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 16:38
//	Comment		:	OJ(P4549)
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

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int CalcGCD(int a, int b)
{
	return b ? CalcGCD(b, a%b) : a;
}

int main(int argc, char* argv[])
{
	int					nInputN;
	int					nAns;
	int					nTemp;
	scanf("%d", &nInputN);

	scanf("%d", &nAns);
	if (nAns < 0)
		nAns = -nAns;

	for (int i = 1; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		if (nTemp < 0)
			nTemp = -nTemp;
		nAns = CalcGCD(nAns, nTemp);
	}

	printf("%d", nAns);
Exit0:
	return 0;
}