/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-30 18:44
//	Comment		:	OJ(P2118)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int CalcGCD(int a, int b)
{
	if (a%b == 0)
		return b;
	return CalcGCD(b, a%b);
}

int main(int argc, char* argv[])
{
	int					nInputA;
	int					nInputB;
	int					nInputL;
	double				fNum				 = 1000000000;
	int					nUp;
	int					nDown;

	scanf("%d%d%d", &nInputA, &nInputB, &nInputL);

	for (int i = 1; i <= nInputL; i++)
		for (int j = 1; j <= nInputL; j++)
		{
			if (CalcGCD(i, j) != 1 || 
				nInputA * 1.0 / nInputB > i * 1.0 / j)
				continue;

			if (i * 1.0 / j - nInputA * 1.0 / nInputB < fNum )
			{
				fNum = i * 1.0 / j - nInputA * 1.0 / nInputB;
				nUp = i;
				nDown = j;
			}
		}


	printf("%d %d\n", nUp, nDown);

Exit0:

	return 0;
}