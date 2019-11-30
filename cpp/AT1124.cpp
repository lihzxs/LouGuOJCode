
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
	int				nInputA;
	int				nInputB;
	int				nInputC;
	int				nTemp;
	int				nMax = -1;
		//scanf("%d%d%d", &nInputA, &nInputB, &nInputC);
	cin >> nInputA >> nInputB >> nInputC;
	nTemp = nInputA * nInputB * nInputC;
	nMax = max(nTemp, nMax);
	nTemp = (nInputA + nInputB) * nInputC;
	nMax = max(nTemp, nMax);
	nTemp = nInputA * nInputB + nInputC;
	nMax = max(nTemp, nMax);
	nTemp = nInputA + nInputB + nInputC;
	nMax = max(nTemp, nMax);
	printf("%d\n", nMax);

Exit0:
	return 0;
}