/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 21:47
//	Comment		:	OJ(P120)
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
	string			szStarName;
	string			szGroupName;

	int				nStarMod			= 1;
	int				nGroupMod			= 1;

	cin >> szStarName;
	cin >> szGroupName;

	for (int i = 0; i < szStarName.length(); i++)
		nStarMod = nStarMod * (szStarName[i] - 'A' + 1) % 47;
	for (int i = 0; i < szGroupName.length(); i++)
		nGroupMod = nGroupMod * (szGroupName[i] - 'A' + 1) % 47;

	if (nGroupMod == nStarMod)
		printf("GO");
	else
		printf("STAY");




Exit0:

	return 0;
}




