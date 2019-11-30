/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 10:41
//	Comment		:	OJ(P3741)
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
	int			nInputN;
	string		szInput;
	BOOL		bFlag		= false;
	int			nAns		= 0;


	scanf("%d", &nInputN);
	cin >> szInput;


	for (int i = 0; i < nInputN - 1; i++)
	{
		if (szInput[i] == 'V' && szInput[i + 1] == 'K')
		{
			szInput[i] = 'x';
			szInput[i + 1] = 'X';
			nAns++;
		}
	}

	for (int i = 0; i < nInputN - 1; i++)
	{
		if (szInput[i] ==  szInput[i + 1])
		{
			nAns++;
			break;
		}
	}

	printf("%d\n", nAns);










Exit0:

	return 0;
}







