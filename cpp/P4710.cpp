/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 22:57
//	Comment		:	OJ(P4710)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;








int main(int argc, char* argv[])
{

	double			fInputV;
	double			fInputS;

	scanf("%lf%lf", &fInputV, &fInputS);

	double fVy = fInputV * cos(fInputS);
	double fVx = fInputV * sin(fInputS);

	double ft = fVy / 10.0;
	double fAnsX = fVx * ft;
	double fAnsY = 5.0 * ft * ft;

	printf("%.10f %.10f", fAnsX, fAnsY);










Exit0:

	return 0;
}