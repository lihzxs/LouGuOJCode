/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 21:19
//	Comment		:	OJ(P1664)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
	int			nInputN;
	int			nInputCheck;
	int			nConCheckDay	= 0;
	int			nConNoCheckDay	= 0;
	int			nAns			= 0;

	scanf("%d", &nInputN);
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nInputCheck);
		if (nInputCheck)
		{
			if (nConNoCheckDay > 0)
				nConCheckDay -= pow(2, nConNoCheckDay - 1);
			nConNoCheckDay = 0;
			if (nConCheckDay < 0)
				nConCheckDay = 0;
			nConCheckDay++;

			if (nConCheckDay < 3)
				nAns += 1;
			else if (nConCheckDay < 7)
				nAns += 2;
			else if (nConCheckDay < 30)
				nAns += 3;
			else if (nConCheckDay < 120)
				nAns += 4;
			else if (nConCheckDay < 365)
				nAns += 5;
			else
				nAns += 6;
		}
		else
		{
			nConNoCheckDay++;
		}
	}

	printf("%d\n", nAns);





Exit0:

	return 0;
}







