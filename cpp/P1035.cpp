/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 21:39
//	Comment		:	OJ(P1035)
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
	int			nCount			= 1;
	double		fInputK;
	double		fItem			= 1;
	double		fSum			= 1;

	scanf("%lf", &fInputK);

	while (fSum <= fInputK)
	{
		nCount++;
		fSum += fItem / nCount;
	}

	printf("%d\n", nCount);








Exit0:

	return 0;
}







