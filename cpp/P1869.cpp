/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-13 15:20
//	Comment		:	OJ(P1869)
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

	int					nInputN;
	long long			nInputM;
	long long			nInputK;
	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%lld%lld", &nInputM, &nInputK);
		if ((nInputM & nInputK) == nInputK)
			printf("1");
		else
			printf("0");
		printf("\n");
	}

Exit0:

	return 0;
}