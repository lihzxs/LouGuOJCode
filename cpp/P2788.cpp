/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 9:53
//	Comment		:	OJ(P2788)
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
	int				nAns						= 0;
	int				nCount						= 0;
	int				nPreIndex					= 0;
	int*			pnSymIndexSeq				= NULL;

	cin >> szInput;

	pnSymIndexSeq = (int*)malloc(szInput.length() * sizeof(int));

	for (int i = 0; i < szInput.length(); i++)
		if (szInput[i] > '9' || szInput[i] < '0')
			pnSymIndexSeq[nCount++] = i;

	pnSymIndexSeq[nCount++] = szInput.length();

	nAns += atoi(szInput.substr(nPreIndex, pnSymIndexSeq[0]).c_str());

	for (int i = 0; i < nCount - 1; i++)
	{
		if (szInput[pnSymIndexSeq[i]] == '-')
			nAns -= atoi(szInput.substr(pnSymIndexSeq[i] + 1, pnSymIndexSeq[i + 1]).c_str());
		else
			nAns += atoi(szInput.substr(pnSymIndexSeq[i] + 1, pnSymIndexSeq[i + 1]).c_str());
	}

	printf("%d", nAns);







Exit0:

	return 0;
}



