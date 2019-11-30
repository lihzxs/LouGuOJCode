/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-4 21:39
//	Comment		:	OJ(P2957)
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
	string			szInputA;
	string			szInputB;
	int				nMax			= 0;
	cin >> szInputA >> szInputB;
	if (szInputA.length() > szInputB.length())
		swap(szInputA, szInputB);

	for (int i = 0; i < szInputA.length(); i++)
	{
		for (int j = 1; j < szInputA.length() - i + 1; j++)
		{
			if (j < nMax)
				continue;
			if (szInputB.find(szInputA.substr(i, j)) != string::npos)
			{
				nMax = j;
			}
				
		}
			
	}

	printf("%d", nMax);



Exit0:
	return 0;
}