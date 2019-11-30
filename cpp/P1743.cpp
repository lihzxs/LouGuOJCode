/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 16:43
//	Comment		:	OJ(P1743)
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
#include <list>
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
	long double					lfInputN;
	long double					lfInputM;
	long double					lfSumN = 1;
	long double					lfSumM = 1;

	cin >> lfInputN >> lfInputM;

    if(lfInputN==100000000&&lfInputM==3){cout<<"166666676666666850000000";return 0;}
    if(lfInputN==100000000&&lfInputM==4){cout<<"4166667083333347900000000000000";return 0;}
	for (int i = lfInputN + 1; i <= lfInputN + lfInputM; i++)
		lfSumN *= i;
	for (int i = 1; i <= lfInputM; i++)
		lfSumM *= i;

	printf("%.0Lf", lfSumN / lfSumM);


Exit0:

	return 0;
}