/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-16 21:04
//	Comment		:	OJ(P1620)
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
	long long			llCountO;
	long long			llCountX;
	long long			llMaxO;
	long long			llMaxX;
	while (scanf("%lld%lld%lld%lld", &llCountO, &llCountX, 
		&llMaxO, &llMaxX) != EOF)
	{
		llMaxO = min(llCountO, llMaxO);
		llMaxX = min(llCountX, llMaxX);
		if (llMaxO == 0)
			printf("%lld", llMaxX);
		else if (llMaxX == 0)
			printf("%lld", llMaxO);
		else if ((llCountO + 1) * llMaxX < llCountX)
			printf("%lld", (llCountO + 1) * llMaxX + llCountO);
		else if ((llCountX + 1) * llMaxO < llCountO)
			printf("%lld", (llCountX + 1) * llMaxO + llCountX);
		else
			printf("%lld", llCountO + llCountX);
		printf("\n");
	}
Exit0:

	return 0;
}