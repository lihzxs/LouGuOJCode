
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


int main(int argc, char* argv[])
{
	int			nA;
	int			nB;
	int			nC;
	int			nD;
	int			nSum;
	cin >> nA >> nB >> nC >> nD;

	nSum = nA + nB + nC + nD;

	printf("%d\n%d\n", (nSum - nSum % 60) / 60, nSum % 60);




Exit0:
	return 0;
}