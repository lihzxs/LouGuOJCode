/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 19:43
//	Comment		:	OJ(P1567)
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
#define	MAXNUM		2000
#define	EPS         1e-8

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
	int			nInputTemp;
	int			nPreInput;
	int			nMaxDays		= 1;
	int			nAns			= 1;
	scanf("%d", &nInputN);

	scanf("%d", &nPreInput);
	for (int i = 1; i < nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		if (nInputTemp > nPreInput)
			nMaxDays++;
		else
			nMaxDays = 1;

		if (nMaxDays > nAns)
			nAns = nMaxDays;
		

		nPreInput = nInputTemp;
	}
	printf("%d", nAns);

Exit0:

	return 0;
}




