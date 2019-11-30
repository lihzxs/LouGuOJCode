/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-11 22:04
//	Comment		:	OJ(P2082)
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
	int				nInputN;
	long long		llMax			= 0;
	long long		llAns			= 0;
	pair<long long, long long>*		prSeq;

	scanf("%d", &nInputN);
	prSeq = new pair<long long, long long>[nInputN];
	for (int i = 0; i < nInputN; i++)
		scanf("%lld%lld", &prSeq[i].first, &prSeq[i].second);

	sort(prSeq, prSeq + nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		if (llMax <= prSeq[i].second)
		{
			llAns += prSeq[i].second - max(llMax, prSeq[i].first) + 1;
			llMax = prSeq[i].second + 1;
		}
			
	}

	printf("%lld", llAns);





Exit0:

	return 0;
}