/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-17 0:13
//	Comment		:	OJ(P1702)
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
	pair<int, int>	prDate[100005];
	int				nAnsL = 0;
	int				nAnsK;
	int				nCount;
	int				nL;
	int				nK;

	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nL, &nK);
		prDate[i].first = nL;
		prDate[i].second = nK;
	}

	for (int i = 1; i <= 5; i++)
	{
		nL = 0;
		nCount = 0;
		for (int j = 0; j < nInputN; j++)
		{
			if (prDate[j].first == i || prDate[j].second == i)
				nCount++;
			else
			{
				if (nCount > nL)
					nL = nCount;
				nCount = 0;
			}
		}
		if (nCount > nL)
			nL = nCount;
		if (nL > nAnsL)
		{
			nAnsL = nL;
			nAnsK = i;
		}
	}

	printf("%d %d", nAnsL, nAnsK);


Exit0:

	return 0;
}