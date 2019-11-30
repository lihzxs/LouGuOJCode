/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-16 21:16
//	Comment		:	OJ(P1877)
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
	int				nBegin;
	int				nMax;
	int**			ppnDp				= NULL;
	int				nTemp;
	scanf("%d%d%d", &nInputN, &nBegin, &nMax);

	ppnDp = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 0; i <= nInputN; i++)
	{
		ppnDp[i] = (int*)malloc((nMax + 1) * sizeof(int));
		memset(ppnDp[i], 0, (nMax + 1) * sizeof(int));
	}

	ppnDp[0][nBegin] = true;

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", &nTemp);
		for (int j = 0; j <= nMax; j++)
		{
			if (ppnDp[i - 1][j])
			{
				if (j - nTemp >= 0)
					ppnDp[i][j - nTemp] = true;
				if (j + nTemp <= nMax)
					ppnDp[i][j + nTemp] = true;
			}
		}
	}

	for (int i = nMax; i >= 0; i--)
		if (ppnDp[nInputN][i])
		{
			printf("%d", i);
			return 0;
		}

	printf("-1");
			





Exit0:

	return 0;
}