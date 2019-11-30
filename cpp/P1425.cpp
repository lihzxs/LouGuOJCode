/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 11:09
//	Comment		:	OJ(P1425)
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
	int			nStartHour;
	int			nStartMinute;
	int			nEndHour;
	int			nEndMinute;
	int			nAnsHour;
	int			nAnsMinute;

	scanf("%d%d%d%d", &nStartHour, &nStartMinute,
		&nEndHour, &nEndMinute);

	if (nStartMinute > nEndMinute)
	{
		nEndHour--;
		nAnsMinute = 60 + nEndMinute - nStartMinute;
	}
	else 
	{
		nAnsMinute = nEndMinute - nStartMinute;
	}

	nAnsHour = nEndHour - nStartHour;

	printf("%d %d\n", nAnsHour, nAnsMinute);
		



Exit0:

	return 0;
}







