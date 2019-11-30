/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-21 19:12
//	Comment		:	OJ(P2388)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{

	long long		llAns				= 0;
	long long		llInputN;
	long long		llTemp;
	long long		llCount5			= 0;

	scanf("%lld", &llInputN);

	for (long long i = 1; i <= llInputN; i++)
	{
		llTemp = i;
		while (llTemp % 5 == 0)
		{
			llCount5++;
			llTemp /= 5;
		}
		llAns += llCount5;
	}

	printf("%lld", llAns);

Exit0:

	return 0;
}