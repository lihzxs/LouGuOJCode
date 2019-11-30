/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-20 18:31
//	Comment		:	OJ(P2920)
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


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nTemp;
	pair<int, int>*	pprDate				= NULL;
	int				nAns;


	scanf("%d", &nInputN);

	pprDate = new pair<int, int>[nInputN];


	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		pprDate[i].second = nTemp;
		scanf("%d", &nTemp);
		pprDate[i].first = nTemp;
	}

	sort(pprDate, pprDate + nInputN);

	nAns = pprDate[nInputN - 1].first;

	for (int i = nInputN - 1; i >= 0; i--)
	{
		if (pprDate[i].first >= nAns)
			nAns -= pprDate[i].second;
		else
			nAns = pprDate[i].first - pprDate[i].second;
	}

	if (nAns < 0)
		printf("-1");
	else
		printf("%d", nAns);



Exit0:
	return 0;
}