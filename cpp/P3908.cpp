/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-6 20:33
//	Comment		:	OJ(P3908)
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
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	long long			llInputN;
	cin >> llInputN;
	if (llInputN % 4 == 0)
		printf("%lld", llInputN);
	else if (llInputN % 4 == 3)
		printf("0");
	else if (llInputN % 4 == 1)
		printf("1");
	else if (llInputN % 4 == 2)
		printf("%lld", llInputN + 1);
Exit0:

	return 0;
}