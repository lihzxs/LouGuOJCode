/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-28 0:18
//	Comment		:	OJ(P1253)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


bool Cmp(pair <long long, int>& a, pair <long long, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}



int main(int argc, char* argv[])
{
	int						nInputN;

	long long				llInputTemp1;
	long long				llInputTemp2;
	pair <long long, int>*	pllSeq				 = NULL;
	scanf("%d", &nInputN);

	pllSeq = new pair <long long, int>[nInputN];

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%lld%lld", &llInputTemp1, &llInputTemp2);
		pllSeq[i].first = llInputTemp1 * llInputTemp2;
		pllSeq[i].second = i + 1;
	}

	sort(pllSeq, pllSeq + nInputN, Cmp);

	//printf("%d", pllSeq[nInputN - 1].second);
	for (int i = 0; i < nInputN; i++)
		printf("%d ", pllSeq[i].second);



Exit0:

	return 0;
}