/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-26 16:39
//	Comment		:	OJ(P2368)
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
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int							nInputN;
	long long					nAns				= 72;
	scanf("%d", &nInputN);

	if (nInputN < 9)
		printf("0");
	else if (nInputN == 9)
		printf("8");
	else
	{
		printf("72");

		for (int i = 10; i < nInputN; i++)
			printf("0");

	}




Exit0:

	return 0;
}