/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-28 20:07
//	Comment		:	OJ(P1413)
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
	int				nInputN;
	
	int				nInputTemp1;
	int				nInputTemp2;
	int				nLimitTime;
	int				nPreTime;
	int				nAns				= 0;
	int**			ppnTime				= NULL;
	int*			pnCount				= NULL;

	pnCount = (int*)malloc(6 * sizeof(int));
	memset(pnCount, 0, 6 * sizeof(int));
	ppnTime = (int**)malloc(6 * sizeof(int*));

	scanf("%d", &nInputN);

	for (int i = 0; i < 6; i++)
		ppnTime[i] = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nInputTemp1, &nInputTemp2);
		ppnTime[nInputTemp1 - 1][pnCount[nInputTemp1 - 1]++] = nInputTemp2;
	}

	for (int i = 0; i < 6; i++)
		sort(ppnTime[i], ppnTime[i] + pnCount[i]);


	for (int i = 0; i < 6; i++)
	{
		nPreTime = 0;
		nLimitTime = 0;
		for (int j = 0; j < pnCount[i]; j++)
		{
			if (ppnTime[i][j] >= nLimitTime)
			{
				nLimitTime = ppnTime[i][j] + 60;
				nAns++;
			}
		}
	}

	printf("%d", nAns);






Exit0:

	return 0;
}