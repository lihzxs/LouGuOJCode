/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 10:32
//	Comment		:	OJ(P1887)
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
#include <set>
using namespace std;
#define	MAXNUM		20
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
	int				nInputN;
	int				nInputM;
	int				nTemp;
	scanf("%d%d", &nInputN, &nInputM);
	nTemp = nInputN % nInputM;
	printf("%d", nInputN / nInputM);
	for (int i = 1; i < nInputM - nTemp; i++)
		printf(" %d", nInputN / nInputM);
	for (int i = 0; i <  nTemp; i++)
		printf(" %d", nInputN / nInputM + 1);
	






Exit0:

	return 0;
}