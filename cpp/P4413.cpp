/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 11:29
//	Comment		:	OJ(P4413)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

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
	double		fR1;
	double		fS;
	double		fAns;

	scanf("%lf%lf", &fR1, &fS);

	fAns = 2 * fS - fR1;

	printf("%.0f\n", fAns);
		



Exit0:

	return 0;
}







