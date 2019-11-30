/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-23 23:13
//	Comment		:	OJ(P5514)
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
	int		nInputN;
	int		nFirst;
	int		nTemp;

	scanf("%d", &nInputN);
	scanf("%d", &nFirst);
	for (int i = 1; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		nFirst ^= nTemp;
	}

	printf("%d", nFirst);
		


Exit0:

	return 0;
}