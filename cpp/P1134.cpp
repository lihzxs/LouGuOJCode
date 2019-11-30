/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-31 19:44
//	Comment		:	OJ(P1134)
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





int main(int argc, char* argv[])
{

	int			nInputN;
	long long	nPreFirst = 1;
	long long	nPreSecond = 0;
	long long	nPreThird = 0;
	int			nCount = 2;
	long long	nTemp;
	long long	nAddItem;

	scanf("%d", &nInputN);
	while (nCount <= nInputN)
	{
		nTemp = nPreSecond * 10 + nPreFirst;
		nTemp *= nCount;
		while (nTemp % 10 == 0)
			nTemp /= 10;
		nPreFirst = nTemp % 10;
		nPreSecond = nTemp / 10;
		nPreSecond %= 1000000;
		nCount++;
	}

	printf("%lld", nPreFirst);





Exit0:
	return 0;
}