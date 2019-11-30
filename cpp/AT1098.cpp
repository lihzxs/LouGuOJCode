
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
	int				nInputN;
	scanf("%d", &nInputN);
	if (nInputN % 40 == 0)
		printf("1\n");
	else
	{
		nInputN %= 40;
		if (nInputN > 20)
			printf("%d\n", 20 - (nInputN - 20) + 1);
		else
			printf("%d\n", nInputN);
	}

Exit0:

	return 0;
}