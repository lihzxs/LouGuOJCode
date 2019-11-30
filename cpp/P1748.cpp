/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 00:51
//	Comment		:	OJ(P1748)
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

	int			nA = 1;
	int			nB = 1;
	int			nC = 1;
	int			nD = 1;
	int			nInputN;
	long long*	pllNum = NULL;
	pllNum = (long long*)malloc((10005) * sizeof(long long));
	memset(pllNum, 0, (10005) * sizeof(long long));

	pllNum[1] = 1;

	for (int i = 2; i <= 10000; i++)
	{
		pllNum[i] = pllNum[nA] * 2;
		if (pllNum[i] > pllNum[nB] * 3)
			pllNum[i] = pllNum[nB] * 3;
		if (pllNum[i] > pllNum[nC] * 5)
			pllNum[i] = pllNum[nC] * 5;
		if (pllNum[i] > pllNum[nD] * 7)
			pllNum[i] = pllNum[nD] * 7;
		if (pllNum[i] == pllNum[nA] * 2)
			nA++;
		if (pllNum[i] == pllNum[nB] * 3)
			nB++;
		if (pllNum[i] == pllNum[nC] * 5)
			nC++;
		if (pllNum[i] == pllNum[nD] * 7)
			nD++;
	}
	while (scanf("%d", &nInputN) != EOF)
		printf("%lld\n", pllNum[nInputN]);


Exit0:
	return 0;
}