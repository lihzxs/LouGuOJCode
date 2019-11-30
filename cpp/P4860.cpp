/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-8 1:23
//	Comment		:	OJ(P4860)
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
	int			nInputT;

	scanf("%d", &nInputT);
	while (nInputT--)
	{
		scanf("%d", &nInputN);
		if (nInputN % 4 == 0)
			printf("Roy wins!");
		else
			printf("October wins!");
		printf("\n");
	}

Exit0:

	return 0;
}