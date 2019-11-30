/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-4 15:15
//	Comment		:	OJ(P5118)
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
	int*				pnSeq			= NULL;
	set<int>			stAns;
	pnSeq = (int*)malloc(22 * sizeof(int));

	for (int i = 1; i <= 20; i++)
		scanf("%d", pnSeq + i);
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 11; j <= 20; j++)
			for (int k = i + 1; k <= 10; k++)
				for (int l = 11; l <= 20; l++)
					if (l != j)
						stAns.insert(-pnSeq[i] + pnSeq[j] - pnSeq[k] + pnSeq[l]);
		for (int k = i; k <= 10; k++)
			for (int l = 11; l <= 20; l++)
				stAns.insert(-pnSeq[k] + pnSeq[l]);

		for (int j = 11; j <= 20; j++)
			stAns.insert(-pnSeq[i] + pnSeq[j]);

		stAns.insert(0);
	}

	printf("%d", stAns.size());
Exit0:
	return 0;
}