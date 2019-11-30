
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
	long long				nN;
	long long				nM;
	long long				nTemp;

	scanf("%lld%lld", &nN, &nM);

	nTemp = 2 * nN;
	if (nTemp > nM)
		printf("%lld", nM / 2);
	else if (nTemp == nM)
		printf("%lld", nN);
	else
	{
		nM -= nTemp;
		nM /= 4;
		printf("%lld", nN + nM);
	}

	printf("\n");

Exit0:

	return 0;
}