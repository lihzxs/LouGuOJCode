/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 13:00
//	Comment		:	OJ(P1851)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		70001
#define	EPS         0.0001

#define ERROR_ID    0

#define PROCESS_ERROR(Condition)    \
{                                   \
        if (!(Condition))           \
        {                           \
            goto Exit0;             \
        }                           \
}


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int			nInputN;

	scanf("%d", &nInputN);


	if (nInputN <= 220)
		printf("220 284");
	else if (nInputN <= 284)
		printf("284 220");
	else if (nInputN <= 1184)
		printf("1184 1210");
	else if (nInputN <= 1210)
		printf("1210 1184");
	else if (nInputN <= 2620)
		printf("2620 2924");
	else if (nInputN <= 2924)
		printf("2924 2620");
	else if (nInputN <= 5020)
		printf("5020 5564");
	else if (nInputN <= 5564)
		printf("5564 5020");
	else if (nInputN <= 6232)
		printf("6232 6368");
	else if (nInputN <= 6368)
		printf("6368 6232");
	else if (nInputN <= 10744)
		printf("10744 10856");
	else if (nInputN <= 10856)
		printf("10856 10744");
	else if (nInputN <= 12285)
		printf("12285 14595");
	else if (nInputN <= 14595)
		printf("14595 12285");
	else if (nInputN <= 17296)
		printf("17296 18416");
	else if (nInputN <= 18416)
		printf("18416 17296");










Exit0:

	return 0;
}






