/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 10:18
//	Comment		:	OJ(P1917)
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
#include <set>
using namespace std;
#define	MAXNUM		20
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


	string			szInput;
	int				nAns			= 0;
	int				nFlag			= 0;
	cin >> szInput;
	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] != '-')
			nAns++;
	}
	if (szInput[1] == 'X')
		nFlag = 1;

	cin >> szInput;
	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] != '-')
			nAns++;
	}
	if (szInput[0] == 'X')
		nFlag = 1;
	if (szInput[2] == 'X')
		nFlag = 1;


	cin >> szInput;
	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] != '-')
			nAns++;
	}
	if (szInput[1] == 'X')
		nFlag = 1;

	if (nFlag && nAns < 4)
		printf("xiaoa will win.\n");
	else
		printf("Dont know.\n");

	printf("%d\n", nAns);






Exit0:

	return 0;
}



