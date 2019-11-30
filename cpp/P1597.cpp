/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 19:408
//	Comment		:	OJ(P1597)
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
#define	MAXNUM		4
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
	int*			pnAnsSeq		= NULL;

	int				nIndex;
	string			szIinput;

	pnAnsSeq = (int*)malloc(MAXNUM * sizeof(int));
	memset(pnAnsSeq, 0, MAXNUM * sizeof(int));


	cin >> szIinput;

	for (int i = 0; i < szIinput.length() - 4; i++)
	{
		if (szIinput[i + 1] == ':' && szIinput[i + 2] == '=')
		{
			if (szIinput[i + 3] >= 'a' && szIinput[i + 3] <= 'c')
				pnAnsSeq[szIinput[i] - 'a'] = pnAnsSeq[szIinput[i + 3] - 'a'];
			else
				pnAnsSeq[szIinput[i] - 'a'] = szIinput[i + 3] - '0';
		}///if (szIinput[i + 1] == ':' && szIinput[i + 2] == '=')
	}///for (int i = 0; i < szIinput.length() - 4; i++)


	printf("%d %d %d\n", pnAnsSeq[0], pnAnsSeq[1], pnAnsSeq[2]);






Exit0:

	return 0;
}







