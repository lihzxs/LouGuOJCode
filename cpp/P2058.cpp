/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-25 15:01
//	Comment		:	OJ(P2058)
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
	int				nInputN;
	int				nInputT;
	int				nInputK;
	int				nTemp;
	int				nAns				= 0;
	pair<int, int>	prTemp;
	int*			pnCount				= NULL;
	queue<pair<int, int>>	qPeople;
	pnCount = (int*)malloc(300005 * sizeof(int));
	memset(pnCount, 0, 300005 * sizeof(int));
	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nInputT, &nInputK);

		while (nInputT - 86400 >= 0 && !qPeople.empty() && 
			qPeople.front().first <= nInputT - 86400)
		{
			prTemp = qPeople.front();
			qPeople.pop();
			pnCount[prTemp.second]--;
			if (pnCount[prTemp.second] == 0)
				nAns--;
		}

		for (int j = 0; j < nInputK; j++)
		{
			scanf("%d", &nTemp);
			prTemp.first = nInputT;
			prTemp.second = nTemp;
			qPeople.push(prTemp);
			if (pnCount[prTemp.second] == 0)
				nAns++;
			pnCount[prTemp.second]++;
		}
		printf("%d\n", nAns);

	}




Exit0:
	return 0;
}