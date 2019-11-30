/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-13 23:50
//	Comment		:	OJ(P3370)
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
	int							nInputN;
	map<string, bool>			mpFlag;
	string						szInput;
	int							nAns;
	scanf("%d", &nInputN);
	nAns = nInputN;
	for (int i = 0; i < nInputN; i++)
	{
		cin >> szInput;
		if (!mpFlag[szInput])
			mpFlag[szInput] = true;
		else
			nAns--;
	}

	printf("%d", nAns);





Exit0:

	return 0;
}