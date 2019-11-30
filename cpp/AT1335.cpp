
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

int	CountOne(int nN)
{
	int		nCount = 0;
	while (nN)
	{
		if (nN % 2)
			nCount++;
		nN /= 2;
	}
	return nCount;
}

int main(int argc, char* argv[])
{
	int		nInputA;
	int		nInputB;
	int		nInputC;
	int		nInputK;
	int		nP1;
	int		nP2;
	scanf("%d%d%d%d", &nInputA, &nInputB, &nInputC, &nInputK);
	scanf("%d%d", &nP1, &nP2);
	if (nP1 + nP2 >= nInputK)
		printf("%d\n", nP1 * (nInputA - nInputC) + 
			nP2 * (nInputB - nInputC));
	else
		printf("%d\n", nP1 * nInputA +
			nP2 * nInputB);

Exit0:

	return 0;
}