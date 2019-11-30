/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 00:40
//	Comment		:	OJ(P3910)
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

int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nLeft;
	int				nRight;

	scanf("%d%d", &nInputN, &nInputM);

	for (int i = sqrt(2 * nInputM); i >= 1; i--)
	{
		if (2 * nInputM % i == 0 && ((2 * nInputM / i) - i + 1) % 2 == 0 &&
			((2 * nInputM / i) - i + 1) / 2 >= 1 && ((2 * nInputM / i) - i + 1) / 2 + i - 1 <= nInputN)
		{
			nLeft = ((2 * nInputM / i) - i + 1) / 2;
			nRight = ((2 * nInputM / i) - i + 1) / 2 + i - 1;
			printf("[%d,%d]\n", nLeft, nRight);
		}
	}
	
Exit0:
	return 0;
}