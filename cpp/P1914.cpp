/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 20:02
//	Comment		:	OJ(P1914)
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
	string		szInput;

	scanf("%d", &nInputN);
	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
		szInput[i] = (szInput[i] - 'a' + nInputN) % 26 + 'a';

	cout << szInput;

Exit0:

	return 0;
}




