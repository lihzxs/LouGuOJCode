/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 00:31
//	Comment		:	OJ(P2434)
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
	int					nInputN;
	pair<int, int>		prDate[50005];
	vector<pair<int, int> > vecOut;
	int					nPre;
	int					nLeft;
	int					nRight;
	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", &prDate[i].first, &prDate[i].second);

	sort(prDate, prDate + nInputN);

	nLeft = prDate[0].first;
	nRight = prDate[0].second;
	for (int i = 1; i < nInputN; i++)
	{
		if (prDate[i].first > nRight)
		{
			printf("%d %d\n", nLeft, nRight);
			nLeft = prDate[i].first;
			nRight = max(nRight, prDate[i].second);
		}
		else
			nRight = max(nRight, prDate[i].second);
		if (i == nInputN - 1)
			printf("%d %d\n", nLeft, nRight);
	}



Exit0:

	return 0;
}