/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 19:01
//	Comment		:	OJ(P5015)
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
	string		szInput;
	int			nAns		= 0;
	getline(cin, szInput);
	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] != ' ' && szInput[i] != '\n')
			nAns++;
	}

	printf("%d", nAns);

Exit0:

	return 0;
}




