/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 18:56
//	Comment		:	OJ(P1181)
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
#define	MAXNUM		2000
#define	EPS         1e-8

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
	int			nInputM;
	int			nPreSum				= 0;
	int			nInputTemp;
	int			nAns				= 1;
	scanf("%d%d", &nInputN, &nInputM);



	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		if (nPreSum + nInputTemp > nInputM)
		{
			nAns++;
			nPreSum = nInputTemp;
		}
		else
			nPreSum += nInputTemp;
	}

	printf("%d", nAns);

Exit0:

	return 0;
}




