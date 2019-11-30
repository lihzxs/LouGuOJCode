/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-4 15:50
//	Comment		:	OJ(P2094)
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
	int				nInputK;
	int				nTemp;
	priority_queue<int>	q;

	scanf("%d%d", &nInputN, &nInputK);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		q.push(nTemp);
	}
		
	while (q.size() > 1)
	{
		nTemp = q.top();
		q.pop();
		nTemp += q.top();
		q.pop();
		nTemp /= nInputK;
		q.push(nTemp);
	}

	printf("%d", q.top());


Exit0:
	return 0;
}