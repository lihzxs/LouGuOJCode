/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-30 15:31
//	Comment		:	OJ(P3669)
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
	int					nInputN;
	pair<int, int>*		ppXtoY;
	int					nInputX;
	int					nInputY;
	int					nMax = NULL;
	scanf("%d", &nInputN);

	ppXtoY = new pair<int, int>[nInputN];

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nInputX, &nInputY);
		ppXtoY[i].first = nInputY;
		ppXtoY[i].second = nInputX;
	}

	sort(ppXtoY, ppXtoY + nInputN);


	int i = 0;
	int j = nInputN - 1;

	while (i <= j)
	{
		if (ppXtoY[i].first + ppXtoY[j].first > nMax)
			nMax = ppXtoY[i].first + ppXtoY[j].first;

		if (ppXtoY[i].second == ppXtoY[j].second)
		{
			ppXtoY[i].second = 0;
			ppXtoY[j].second = 0;
			i++;
			j--;
		}
		else if (ppXtoY[i].second > ppXtoY[j].second)
		{
			
			ppXtoY[i].second -= ppXtoY[j].second;
			ppXtoY[j].second = 0;
			j--;
		}
		else if (ppXtoY[i].second < ppXtoY[j].second)
		{
			
			ppXtoY[j].second -= ppXtoY[i].second;
			ppXtoY[i].second = 0;
			i++;
		}
	}






	printf("%d", nMax);



Exit0:

	return 0;
}