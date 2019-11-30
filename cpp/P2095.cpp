/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-23 22:26
//	Comment		:	OJ(P2095)
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
	int				nInputM;
	int				nInputK;
	int*			pnMaxPreFood			= NULL;
	int*			pnCountPreFood			= NULL;
	int				nNumFood				= 0;
	int				nAns					= 0;
	pair<int, int>*	ppairFoodNum			= NULL;

	

	scanf("%d%d%d", &nInputN, &nInputM, &nInputK);
	ppairFoodNum = new pair<int, int>[nInputN];
	pnMaxPreFood = (int*)malloc((nInputK + 1) * sizeof(int));
	pnCountPreFood = (int*)malloc((nInputK + 1)* sizeof(int));
	memset(pnCountPreFood, 0, (nInputK + 1) * sizeof(int));

	for (int i = 1; i < nInputK + 1; i++)
		scanf("%d", pnMaxPreFood + i);

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", &ppairFoodNum[i].first, &ppairFoodNum[i].second);

	sort(ppairFoodNum, ppairFoodNum + nInputN);

	for (int i = nInputN - 1; i >= 0; i--)
	{
		if (nNumFood == nInputM)
			break;

		if (pnCountPreFood[ppairFoodNum[i].second] + 1 >
			pnMaxPreFood[ppairFoodNum[i].second])
			continue;

		pnCountPreFood[ppairFoodNum[i].second]++;
		nNumFood++;	
		nAns += ppairFoodNum[i].first;
	}

	printf("%d", nAns);




Exit0:

	return 0;
}