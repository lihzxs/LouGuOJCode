/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 11:09
//	Comment		:	OJ(P4413)
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
	stack<int>		nNumContainer;
	int				nTemp;
	while (scanf("%d", &nTemp))
	{
		if (nTemp == 0)
			break;
		nNumContainer.push(nTemp);
	}
	cout << nNumContainer.top();
	nNumContainer.pop();
	while (!nNumContainer.empty())
	{
		cout << ' ' << nNumContainer.top();
		nNumContainer.pop();
	}
		



Exit0:

	return 0;
}







