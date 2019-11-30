/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-31 21:17
//	Comment		:	OJ(P4369)
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
	int			nInputX;
	int			nInputK;

	scanf("%d%d", &nInputX, &nInputK);

	for (int i = 1; i < nInputK; i++)
		printf("%d 0\n", i);
	printf("%d 1\n", nInputX - nInputK + 1);

Exit0:
	return 0;
}