/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 10:49
//	Comment		:	OJ(P1075)
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
#include <math.h>
using namespace std;
//#define	MAXNUM		3000
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


BOOL IsPrime(int nNum)
{
	for (int i = 2; i < sqrt(nNum); i++)
		if (nNum % i == 0)
			return false;

	return true;
}

int main(int argc, char* argv[])
{

	int					nInputN;

	scanf("%d", &nInputN);






	for (int i = 2; i <= nInputN; i++)
	{
		if (nInputN % i == 0)
		{
			printf("%d", nInputN / i);
			return 0;
		}
			
	}












Exit0:





	return 0;
}




