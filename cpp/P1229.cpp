/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-6 22:06
//	Comment		:	OJ(P1229)
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{

	string			szA;
	string			szB;
	int				nAns			= 1;
	int				nIndex;
	cin >> szA;
	cin >> szB;

	for (int i = 0; i < szA.length(); i++)
	{
		nIndex = 0;
		for (int j = 0; j < szA.length(); j++)
		{
			if (szA[i] == szB[j])
			{
				nIndex = j;
				break;
			}
		}
		if (nIndex != 0 && (szA[i + 1] == szB[nIndex - 1]))
			nAns *= 2;
	}

	printf("%d", nAns);
Exit0:

	return 0;
}