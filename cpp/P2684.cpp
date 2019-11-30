/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-28 15:53
//	Comment		:	OJ(P2684)
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
	int				nInputT;
	int				nTime;
	int				nAns				= 0;
	int				nStart;
	int				nEnd;
	int*			pnFlag				= NULL;
	int				nTemp;
	scanf("%d%d", &nInputN, &nInputT);

	pnFlag = (int*)malloc(1000002 * sizeof(int));
	memset(pnFlag, 0, 1000002 * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		if (pnFlag[nStart] < nEnd)
			pnFlag[nStart] = nEnd;
	}

	nStart = 1;
	nEnd = 1;
	nTemp = 0;

	while(nTemp < nInputT)
	{
		for (int i = nStart; i <= nEnd; i++)
			nTemp = max(nTemp, pnFlag[i]);

		if (nTemp < nEnd)
		{
			printf("-1");
			return 0;
		}
		nAns++;
		nStart = nEnd + 1;
		nEnd = nTemp + 1;
	}

	printf("%d", nAns);

Exit0:

	return 0;
}