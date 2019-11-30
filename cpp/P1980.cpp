/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 21:53
//	Comment		:	OJ(P1980)
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
	int			nInputN;
	int			nInputX;
	int			nAns			= 0;
	string		szNum;

	scanf("%d%d", &nInputN, &nInputX);

	for (int i = 1; i <= nInputN; i++)
	{
		szNum = to_string(i);
		for (int j = 0; j < szNum.length(); j++)
		{
			if (szNum[j] - '0' == nInputX)
				nAns++;
		}
	}

	printf("%d", nAns);




Exit0:

	return 0;
}




