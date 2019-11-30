/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-24 23:52
//	Comment		:	OJ(P5582)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <list>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		1000000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int CalcGCD(int a, int b)
{
	if (a % b == 0)
		return b;
	return CalcGCD(b, a % b);
}

int main(int argc, char* argv[])
{

	int			nInputT;
	int			nInputN;
	int			nInputK;
	int*		pnFlag				= NULL;
	int			nTemp;
	int			nAns;
	scanf("%d", &nInputT);

	pnFlag = (int*)malloc(1000001 * sizeof(int));
	

	while (nInputT--)
	{
		scanf("%d%d", &nInputN, &nInputK);
		memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
		nAns = nInputN;
		for (int i = 0; i < nInputK; i++)
		{
			scanf("%d", &nTemp);
			pnFlag[nTemp] = 1;
		}
		if (nInputN == 1 && nInputK == 1)
		{
		    printf("-1\n");
		    continue;
		}
		for (int i = nInputN; i >= 1; i--)
		{
			if (!pnFlag[i])
				nAns = CalcGCD(nAns, i);
		}
		if (nAns == 1)
			printf("%d\n", nInputN);
		else
			printf("-1\n");
	}


Exit0:

	return 0;
}