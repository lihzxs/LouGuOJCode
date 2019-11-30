/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-7 22:46
//	Comment		:	OJ(P5436)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int							nInputN;
	int*						pnSeq;
	int							nAns			 = 0;
	int							nTemp;
	scanf("%d", &nInputN);

	while (nInputN--)
	{
		scanf("%d", &nTemp);
		if (nTemp == 1)
			printf("1\n");
		else
			printf("%lld\n", nTemp * (nTemp - 1L));
	}






Exit0:

	return 0;
}