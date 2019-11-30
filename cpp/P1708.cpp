/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-27 16:57
//	Comment		:	OJ(P1708)
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
	long long			llSumX				= 0;
	long long			llSumY				= 0;
	long long			llInputX;
	long long			llInputY;
	int					nInputN;

	scanf("%d", &nInputN);


	for (int i = 0; i < nInputN; i++)
	{
		scanf("%lld%lld", &llInputX, &llInputY);
		llSumX += llInputX;
		llSumY += llInputY;
	}
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%lld%lld", &llInputX, &llInputY);
		llSumX -= llInputX;
		llSumY -= llInputY;
	}
	if (llSumX < 0)
		llSumX = -llSumX;

	if (llSumY < 0)
		llSumY = -llSumY;

	printf("%lld", llSumX + llSumY);



Exit0:

	return 0;
}