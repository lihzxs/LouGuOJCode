/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-20 20:52
//	Comment		:	OJ(P2799)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		7010
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	string				szInput;

	cin >> szInput;

	while (szInput[0] == szInput[szInput.length() - 1] && 
		szInput.length() % 2 == 0)
	{
		szInput = szInput.substr(0, szInput.length() / 2);
	}

	printf("%d", szInput.length());

Exit0:

	return 0;
}