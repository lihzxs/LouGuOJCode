/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-26 23:56
//	Comment		:	OJ(P2415)
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

	long long			llAns = 0;
	int					nTemp;
	int					nCount = 0;

	while (scanf("%d", &nTemp) != EOF)
	{
		llAns += nTemp;
		nCount++;
	}
		

	for (int i = 1; i < nCount; i++)
		llAns *= 2;

	printf("%lld", llAns);

Exit0:
	return 0;
}