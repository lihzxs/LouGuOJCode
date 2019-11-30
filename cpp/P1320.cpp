/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 11:10
//	Comment		:	OJ(P1320)
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
	string			szInput;
	int				nCount[2]		= {0, 0};
	int				nLength;
	int				nJudge			= 0;
	cin >> szInput;
	nLength = szInput.length();
	printf("%d", nLength);
	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] - '0'== nJudge)
			nCount[nJudge]++;
		else
		{
			printf(" %d", nCount[nJudge]);
			nJudge = !nJudge;
			nCount[nJudge] = 1;
		}

	}
	for (int i = 0; i < nLength - 1; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
		{
			if (szInput[j] - '0' == nJudge)
				nCount[nJudge]++;
			else
			{
				printf(" %d", nCount[nJudge]);
				nJudge = !nJudge;
				nCount[nJudge] = 1;
			}
		}
	}
	printf(" %d", nCount[nJudge]);
	printf("\n");












Exit0:

	return 0;
}







