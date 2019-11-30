/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-29 16:27
//	Comment		:	OJ(P1795)
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
	int				nInputN;
	int				nInputQ;

	scanf("%d", &nInputN);

	while (nInputN--)
	{
		scanf("%d", &nInputQ);
		nInputQ--;
		if (int(int(sqrt(2 * nInputQ)) * int(sqrt(2 * nInputQ) + 1)) == 2 * nInputQ)
			printf("1\n");
		else
			printf("0\n");
	}



Exit0:

	return 0;
}