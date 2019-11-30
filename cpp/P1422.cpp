/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 13:07
//	Comment		:	OJ(P4422)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string>
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
	
	double			fAns		= 0;
	int				nInput;
	scanf("%d", &nInput);
	if (nInput > 400)
	{
		fAns += (nInput - 400) * 0.5663;
		nInput = 400;
	}
	if (nInput > 150)
	{
		fAns += (nInput - 150) * 0.4663;
		nInput = 150;
	}

	fAns += nInput * 0.4463;

	printf("%.1f\n", fAns);
		
	

		



Exit0:

	return 0;
}







