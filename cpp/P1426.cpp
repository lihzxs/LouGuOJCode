/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 15:31
//	Comment		:	OJ(P1426)
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
#define	MAXNUM		150
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


int				g_nMat[MAXNUM][MAXNUM];
int main(int argc, char* argv[])
{
	double			fInputS;
	double			fInputX;
	double			fSwimLength			= 7;
	double			fSum				= 0;	
	scanf("%lf%lf", &fInputS, &fInputX);
	while (fSum < fInputS - fInputX)
	{

		fSum += fSwimLength;
		fSwimLength *= 0.98;
		
	}

	if (fSum + fSwimLength <= fInputS + fInputX)
		printf("y");
	else
		printf("n");




Exit0:

	return 0;
}




