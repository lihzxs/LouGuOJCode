/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 14:2
//	Comment		:	OJ(P1554)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
using namespace std;
#define  MAXNUM		10

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
	unsigned int*			punSeq			= NULL;
	long					lStart			= 0;
	long					lTemp			= 0;
	long					lEnd			= 0;

	punSeq = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));
	memset(punSeq, 0, MAXNUM * sizeof(unsigned int));

	scanf("%ld%ld", &lStart, &lEnd);

	for (long i = lStart; i <= lEnd; i++)
	{
		lTemp = i;
		while (lTemp != 0) 
		{
			punSeq[lTemp % 10]++;
			lTemp /= 10;
		}
	}
	printf("%d", punSeq[0]);
	for (int i = 1; i < 10; i++)
	{
		printf(" %d", punSeq[i]);
	}
	printf("\n");
	

		



Exit0:

	return 0;
}







