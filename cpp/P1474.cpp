/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-19 22:22
//	Comment		:	OJ(P1474)
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
	int				nInputV;
	int				nInputN;
	long long*		llSeq				= NULL;
	int				nTemp;
	scanf("%d%d", &nInputV, &nInputN);

	llSeq = (long long*)malloc((nInputN + 1) * sizeof(long long));
	memset(llSeq, 0, (nInputN + 1) * sizeof(long long));

	llSeq[0] = 1;

	for (int i = 0; i < nInputV; i++)
	{
		scanf("%d", &nTemp);
		for (int j = nTemp; j <= nInputN; j++)
			llSeq[j] += llSeq[j - nTemp];
	}

	printf("%lld", llSeq[nInputN]);




Exit0:
	return 0;
}