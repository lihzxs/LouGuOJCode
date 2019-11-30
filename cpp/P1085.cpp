/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 14:39
//	Comment		:	OJ(P1085)
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
#define	MAXNUM		7
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
	int			nInputA;
	int			nInputB;
	int			nMaxTime		= 0;
	int			nAns;
	for (int i = 0; i < MAXNUM; i++)
	{
		scanf("%d%d", &nInputA, &nInputB);
		if (nInputA + nInputB >= 8 && nInputA + nInputB > nMaxTime)
		{
			nAns = i + 1;
			nMaxTime = nInputA + nInputB;
		}
	}

	printf("%d", nAns);










Exit0:

	return 0;
}




