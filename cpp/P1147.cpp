/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-23 12:12
//	Comment		:	OJ(P1147)
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
	int			nInputN;
	scanf("%d", &nInputN);


	for (int i = int(sqrt(2 * nInputN)); i > 1 ; i--)
	{
		if (2 * nInputN % i == 0)
		{
			if ((2 * nInputN / i - i + 1) % 2 == 0 &&
				(2 * nInputN / i + i - 1) % 2 == 0 && (2 * nInputN / i - i + 1) != 
				(2 * nInputN / i + i - 1))
				printf("%d %d\n", (2 * nInputN / i - i + 1) / 2,
				(2 * nInputN / i + i - 1) / 2);
		}
	}



		




Exit0:

	return 0;
}