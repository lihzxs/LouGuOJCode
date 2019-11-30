/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-28 16:17
//	Comment		:	OJ(P1293)
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

typedef struct SCityInfo
{
	int			nPeople;
	int			nDis;
	string		szName;
}SCityInfo;





int main(int argc, char* argv[])
{
	
	SCityInfo*			psCityInfo			= NULL;
	int					nCount				= 0;
	long long			llMin				= 100000000;
	long long			llSum				= 0;
	int					nIndex;
	psCityInfo = new SCityInfo[160];

	while (true)
	{
		cin >> psCityInfo[nCount].nPeople >> psCityInfo[nCount].nDis
			>> psCityInfo[nCount].szName;
		nCount++;
		if (psCityInfo[nCount - 1].szName == "Moscow")
			break;
	}

	for (int i = 0; i < nCount; i++)
	{
		for (int j = 0; j < nCount; j++)
		{
			if (j == i)
				continue;

			llSum += abs(psCityInfo[i].nDis - 
				psCityInfo[j].nDis) * psCityInfo[j].nPeople;
		}
		if (llMin >= llSum)
		{
			llMin = llSum;
			nIndex = i;
		}
		llSum = 0;
	}

	cout << psCityInfo[nIndex].szName << " " << llMin << endl;







Exit0:

	return 0;
}