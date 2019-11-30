/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 17:09
//	Comment		:	OJ(P5269)
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
	int				nInputT;
	int				nInputN;
	int				nInputL;
	int				nInputR;
	int				nInputX;
	int				nInputK;
	long long		nV;
	int				nX;
	int				nY;
	int				nK				= 0;
	long long				nD				= 1;
	long long				nAns			= 0;
	scanf("%d%d%d%d%d%d", &nInputT, &nInputN, &nInputL, &nInputR, &nInputX, &nInputK);
	nV = nInputL;

	for (int i = 0; i < nInputT; i++)
	{
		scanf("%d%d", &nX, &nY);
		if (nX == 0)
		{
			nV = nInputL;
			nD++;
			if (nD > nInputN)
			{
				printf("-1");
				return 0;
			}
		}
		else if (nX == 1)
		{
			nV = nInputR;
			nD--;
			if (nD < 1)
			{
				printf("-1");
				return 0;
			}
		}

		if (nY)
		{
			nV += nInputX;
			if (nV > nInputR)
				nV = nInputR;
		}
		nAns += nV * nD;
		if (nV == nInputR)
		{
			nK++;
			if (nK == nInputK)
			{
				printf("%lld", nAns);
				return 0;
			}
		}
		else
			nK = 0;
	}
	printf("%lld", nAns);
Exit0:
	return 0;
}