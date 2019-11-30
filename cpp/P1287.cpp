/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-7 23:05
//	Comment		:	OJ(P1287)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

long long Ans(long long llN, long long llM)
{
	if (llM <= 0 || llN < llM)
		return 0;
	else if (llN == llM)
		return 1;
	else
		return Ans(llN - 1, llM - 1) + Ans(llN - 1, llM) * llM;
}


int main(int argc, char* argv[])
{
	int							nInputN;
	int							nInputM;
	long long					llTemp = 1;

	scanf("%d%d", &nInputN, &nInputM);

	for (int i = 1; i <= nInputM; i++)
		llTemp *= i;


	printf("%lld\n", Ans(nInputN, nInputM) * llTemp);




Exit0:

	return 0;
}