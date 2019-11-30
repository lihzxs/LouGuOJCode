/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-5 21:56
//	Comment		:	OJ(P2032)
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
	int					nInputN;
	int					nInputK;
	
	int*				pnSeq				= NULL;
	priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > >  qAns;
	scanf("%d%d", &nInputN, &nInputK);
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	
	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	for (int i = 1; i <= nInputN; i++)
	{
		qAns.push({ pnSeq[i], i });
		if (i >= nInputK)
		{
			while (qAns.top().second <= i - nInputK)
				qAns.pop();
			printf("%d\n", qAns.top().first);
		}
	}


Exit0:
	return 0;
}