/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 17:52
//	Comment		:	OJ(P2084)
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
#define	MAXNUM		7
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
	int			nDec;
	string		szInput		= "";
	string		szOutput	= "";

	scanf("%d", &nDec);
	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] == '0')
			continue;
		szOutput += to_string(szInput[i] - '0') + "*" + to_string(nDec) 
			+ "^" + to_string(szInput.length() - 1 - i) + "+";
	}

	szOutput[szOutput.length() - 1] = '\0';
	cout << szOutput << endl;





Exit0:

	return 0;
}







