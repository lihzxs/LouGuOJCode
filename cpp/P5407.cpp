/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-20 00:36
//	Comment		:	OJ(P5407)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int Count(int nLeft, int nRight)
{
	int			nAns	= 0;

	for (int i = nLeft; i <= nRight; i++)
		if (i % 4 == 0)
			nAns++;
	return nAns;
}
int nAns[10] = { 14, 13, 12, 11, 10, 9, 8 };
int main(int argc, char* argv[])
{
	int				nInputN;

	cin >> nInputN;

	cout << nAns[((nInputN - 1911) + Count(1911, nInputN)) % 7];






Exit0:
	return 0;
}