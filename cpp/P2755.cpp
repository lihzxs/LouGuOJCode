/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-11 23:30
//	Comment		:	OJ(P2755)
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
#include <list>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int						nInputN;
	int						nTemp			= 1;
	int						nAns			= 0;
	scanf("%d", &nInputN);
	if (nInputN == 0)
	{
		printf("1");
		return 0;
	}

	nTemp = (nTemp * 2) % (2 * nInputN + 1);
	nAns = 1;
	while (nTemp != 1)
	{
		nTemp = (nTemp * 2) % (2 * nInputN + 1);
		nAns++;
	}

	printf("%d", nAns);



Exit0:

	return 0;
}