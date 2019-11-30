/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-2 16:17
//	Comment		:	OJ(P2983)
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





int main(int argc, char* argv[])
{
	int			nInputN;
	long long			nInputB;
	pair<long long, long long>*	pprD	= NULL;
	int*		pnBagForm				= NULL;
	long long			nP;
	long long			nC;
	long long			nAns			= 0;
	scanf("%d%lld", &nInputN, &nInputB);
	pprD = new pair<long long, long long>[nInputN];
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%lld%lld", &nP, &nC);
		pprD[i].first = nP;
		pprD[i].second = nC;
	}

	sort(pprD, pprD + nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		if (pprD[i].first  <= nInputB / pprD[i].second)
		{
			nAns += pprD[i].second;
			nInputB -= pprD[i].first * pprD[i].second;
		}
		else
		{
			nAns += nInputB / pprD[i].first;
			break;
		}
	}

	printf("%lld", nAns);





Exit0:

	return 0;
}