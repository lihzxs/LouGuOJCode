/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 20:48
//	Comment		:	OJ(P1424)
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
#define	MAXNUM		5
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
	int			nInputX;
	int			nInputN;
	int			nAns			= 0;
	scanf("%d%d", &nInputX, &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		if (nInputX < 6)
			nAns += 250;
		if (nInputX == 7)
			nInputX = 0;

		nInputX++;

	}

	printf("%d\n", nAns);




Exit0:

	return 0;
}







