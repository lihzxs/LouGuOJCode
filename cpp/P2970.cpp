/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-16 00:14
//	Comment		:	OJ(P2970)
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nLeft;
	int				nRight;
	int				nMax			= 0;
	int				nAns			= 0;

	pair<int, int>	pairM[50005];

	scanf("%d", &nInputN);
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nLeft, &nRight);
		pairM[i].first = nRight;
		pairM[i].second = nLeft;
	}

	sort(pairM, pairM + nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		if (pairM[i].second >= nMax)
		{
			nAns++;
			nMax = pairM[i].first;
		}
	}

	printf("%d", nAns);




Exit0:

	return 0;
}