/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-12 00:10
//	Comment		:	OJ(P2735)
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
int CalcGCD(int a, int b)
{
	return b ? CalcGCD(b, a%b) : a;
}
int main(int argc, char* argv[])
{
	int			nN;
	int			nM;
	int			nP;
	int			nTemp;
	int			nS;
	int			nAns;
	scanf("%d%d%d", &nN, &nM, &nP);
	nTemp = CalcGCD(nN, nM) + CalcGCD(abs(nP - nN), nM) + nP;
	nS = (nP * nM) / 2;
	nAns = nS - nTemp / 2 + 1;
	printf("%d", nAns);
Exit0:

	return 0;
}