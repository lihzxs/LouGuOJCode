/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 22:27
//	Comment		:	OJ(P1100)
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
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		3
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	unsigned long long				ullInputN;
	scanf("%llu", &ullInputN);
	printf("%llu", ((ullInputN & 0x0000ffff) << 16 |
		(ullInputN & 0xffff0000) >> 16));

Exit0:

	return 0;
}