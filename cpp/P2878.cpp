/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-7 22:53
//	Comment		:	OJ(P2878)
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

bool Cmp(pair<int, int>& prFirst, pair<int, int>& prSecond)
{
	return prFirst.first * prSecond.second < prFirst.second * prSecond.first;
}


int main(int argc, char* argv[])
{
	int								nInputN;
	int								nT;
	int								nD;
	long long						llAns				= 0;
	int								nTime				= 0;
	pair<int, int>					prDate[100005];

	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nT, &nD);
		prDate[i] = { nT, nD };
	}

	sort(prDate, prDate + nInputN, Cmp);

	for (int i = 0; i < nInputN; i++)
	{
		llAns += nTime * prDate[i].second;
		nTime += 2 * prDate[i].first;
	}

	printf("%lld", llAns);







Exit0:

	return 0;
}