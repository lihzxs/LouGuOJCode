/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-12 21:21
//	Comment		:	OJ(P4960)
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
	int			nInputN;
	int			nMax = 0;
	int			nSize;
	int			nTemp;
	map<int, int>	pnCount;

	scanf("%d", &nInputN);
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		pnCount[nTemp]++;
		nMax = max(nMax, pnCount[nTemp]);
	}

	nSize = pnCount.size();

	if (nSize < nMax)
	{
		printf("%d 1\n", nSize);
		for (map<int, int>::iterator iter = pnCount.begin(); 
			iter != pnCount.end(); iter++)
		{
			printf("%d ", iter->second);
			for (int j = 1; j <= iter->second; j++)
				printf("%d ", iter->first);
			printf("\n");
		}
	}
	else
	{
		printf("%d 2\n", nMax);
		for (int i = 0; i < nMax; i++)
		{
			printf("%d ", pnCount.size());
			for (map<int, int>::iterator iter = pnCount.begin();
				iter != pnCount.end(); )
			{
				if (pnCount[iter->first] > 0)
				{
					printf("%d ", iter->first);
					pnCount[iter->first]--;
				}
				map<int, int>::iterator iterTemp = iter;
				iter++;
				if (iterTemp->second == 0)
					pnCount.erase(iterTemp);
			}
			printf("\n");
		}
	}


Exit0:

	return 0;
}