
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-23 00:42
//	Comment		:	OJ(P2646)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{


	long long llCountZ			= 0;
	long long llAns				= 0;

	string		szInput;

	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] == 'z')
			llCountZ++;
		if (szInput[i] == 'y')
			llAns += llCountZ * (llCountZ - 1) / 2;
	}

	cout << llAns;



Exit0:

	return 0;
}