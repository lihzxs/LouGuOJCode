/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-31 18:12
//	Comment		:	OJ(P2543)
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
	string			sA;
	string			sB;
	int**			ppnDp		= NULL;
	cin >> sA >> sB;

	sA = " " + sA;
	sB = " " + sB;

	ppnDp = (int**)malloc((sA.length() + 1) * sizeof(int*));

	for (int i = 0; i <= sA.length(); i++)
	{
		ppnDp[i] = (int*)malloc((sB.length() + 1) * sizeof(int));
		memset(ppnDp[i], 0, (sB.length() + 1) * sizeof(int));
	}

	for (int i = 1; i < sA.length(); i++)
		for (int j = 1; j < sB.length(); j++)
		{
			if (sA[i] == sB[j])
				ppnDp[i][j] = ppnDp[i - 1][j - 1] + 1;
			else
				ppnDp[i][j] = max(ppnDp[i][j - 1], ppnDp[i - 1][j]);
		}
	printf("%d", ppnDp[sA.length() - 1][sB.length() - 1]);
		





Exit0:
	return 0;
}