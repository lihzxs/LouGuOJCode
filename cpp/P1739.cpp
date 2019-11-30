/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 21:40
//	Comment		:	OJ(P1739)
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
#include <vector>
#include <map>
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
	string			szInput;
	stack<BYTE>		byStack;

	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] == '(')
		{
			byStack.push(szInput[i]);
		}
		if (szInput[i] == ')')
		{
			if (byStack.empty())
				byStack.push(szInput[i]);
			else
			{
				if (byStack.top() == '(')
					byStack.pop();
				else
					byStack.push(szInput[i]);
			}
		}///if (szInput[i] == ')')
	}

	if (byStack.empty())
		printf("YES");
	else
		printf("NO");

Exit0:

	return 0;
}




