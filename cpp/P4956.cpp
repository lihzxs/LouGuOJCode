/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 10:27
//	Comment		:	OJ(P4956)
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
#define	MAXNUM		30001
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
	int			nInput;
	int			nWeekMoney;
	int			nAnsX				= 1;
	int			nAnsK				= 1;

	scanf("%d", &nInput);
	nWeekMoney = nInput / 52;

	nAnsX = (nWeekMoney - 21 * nAnsK) / 7;

	while (7 * nAnsX + 21 * nAnsK != nWeekMoney || nAnsX > 100)
	{
		nAnsK++;
		nAnsX = (nWeekMoney - 21 * nAnsK) / 7;
	}

	printf("%d\n%d\n", nAnsX, nAnsK);









Exit0:

	return 0;
}







