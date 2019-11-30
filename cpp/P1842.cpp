/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-14 16:57
//	Comment		:	OJ(P1842)
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
bool Cmp(pair<int, int>& prA, pair<int, int>& prB)
{
	return prA.first + prA.second < prB.first + prB.second;
}


int main(int argc, char* argv[])
{
	int				nInputN;
	pair<int, int>*	prTemp;
	long long		nSum		= 0;
	long long		nMax		= -1000000000000;
	scanf("%d", &nInputN);
	prTemp = new pair<int, int>[nInputN];

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &prTemp[i].first, &prTemp[i].second);
		nSum += prTemp[i].first;
	}
		


	sort(prTemp, prTemp + nInputN, Cmp);

	for (int i = nInputN - 1; i >= 0; i--)
	{
		nSum -= prTemp[i].first;
		nMax = max(nMax, nSum - prTemp[i].second);
	}


	printf("%d", nMax);
Exit0:

	return 0;
}