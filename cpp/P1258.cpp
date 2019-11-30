/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-23 11:17
//	Comment		:	OJ(P1258)
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
	double			fInputN;
	double			fInputA;
	double			fInputB;
	double			fAns;
	scanf("%lf%lf%lf", &fInputN, &fInputA, &fInputB);

	fAns = (2 * fInputA * fInputN) / (3 * fInputA + fInputB);

	printf("%.6f", fAns / fInputA + (fInputN - fAns) / fInputB);



		




Exit0:

	return 0;
}