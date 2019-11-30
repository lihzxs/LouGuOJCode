/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-28 21:38
//	Comment		:	OJ(P4851)
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
	int				nInputA;
	int				nInputB;
	int				nInputC;
	int				nInputD;
	int				nInputE;
	int				nInputF;
	int				nInputG;
	int				nInputH;
	int				nInputK;
	int				nInputX;
	int				nInputY;
	int				nLP;
	int				nEXP;
	int				nPT = 0;
	long long		llCount = 0;
	scanf("%d", &nInputA);
	scanf("%d", &nInputB);
	scanf("%d", &nInputC);
	scanf("%d", &nInputD);
	scanf("%d", &nInputE);
	scanf("%d", &nInputF);
	scanf("%d", &nInputG);
	scanf("%d", &nInputH);
	scanf("%d", &nInputK);
	scanf("%d", &nInputX);
	scanf("%d", &nInputY);

	nLP = nInputD + nInputX;
	nEXP = nInputF;

	while (nPT < nInputY)
	{
		while (nLP < nInputB)
		{
			llCount++;
			nLP += nInputC;
		}
		nLP = nLP - nInputB;
		nPT = nPT + nInputA;
		nEXP += nInputG;
		if (nEXP >= nInputE)
		{
			nEXP = nEXP - nInputE;
			nInputE += nInputK;
			nInputC += nInputH;
			nLP += nInputC;
		}

	}

	printf("%lld", llCount);
Exit0:

	return 0;
}