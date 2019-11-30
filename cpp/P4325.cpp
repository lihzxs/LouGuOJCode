/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 13:34
//	Comment		:	OJ(P4325)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
using namespace std;
#define  MAXNUM		42

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
	int						nAns			= 0;
	int						nInputTemp;

	punSeq = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));
	memset(punSeq, 0, MAXNUM * sizeof(unsigned int));

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &nInputTemp);
		punSeq[nInputTemp % 42] = 1;
	}

	for (int i = 0; i < 42; i++)
	{
		if (punSeq[i])
			nAns++;
	}
		
	printf("%d\n", nAns);
	

		



Exit0:

	return 0;
}







