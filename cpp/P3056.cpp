/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 23:20
//	Comment		:	OJ(P3056)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	string			szInput;
	int				nAns			= 0;
	int				nCount			= 0;
	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] == '(')
			nCount++;
		else if (szInput[i] == ')' && nCount == 0)
		{
			nCount++;
			nAns++;
		}
		else
			nCount--;
	}

	nAns += (nCount + 1) / 2;
	printf("%d", nAns);













Exit0:
	return 0;
}