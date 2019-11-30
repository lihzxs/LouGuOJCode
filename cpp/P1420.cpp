/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 14:36
//	Comment		:	OJ(P1420)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string>
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
	int						nInputTemp		= -1;
	int						nPreInput		= -1;
	int						nMaxSeq			= 1;
	int						nMaxAns			= 1;
	int						nNum;
	

	scanf("%d", &nNum);


	for (int i = 0; i < nNum; i++)
	{
		scanf("%d", &nInputTemp);
		if (nPreInput + 1 == nInputTemp)
			nMaxSeq++;
		else
		{
			if (nMaxAns < nMaxSeq)
				nMaxAns = nMaxSeq;
			nMaxSeq = 1;
		}
		nPreInput = nInputTemp;
	}

	printf("%d\n", nMaxAns);

	

		



Exit0:

	return 0;
}







