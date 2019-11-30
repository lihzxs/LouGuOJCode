/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-17 22:53
//	Comment		:	OJ(P2241)
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
	long long			llN;
	long long			llM;

	long long			llOutZ = 0;
	long long			llOutJ = 0;

	scanf("%lld%lld", &llN, &llM);

	for (int i = 0; i < llN; i++)
		for (int j = 0; j < llM; j++)
			if (i == j)
				llOutZ += (llN - i) * (llM - j);
			else
				llOutJ += (llN - i) * (llM - j);

	printf("%lld %lld", llOutZ, llOutJ);
Exit0:

	return 0;
}