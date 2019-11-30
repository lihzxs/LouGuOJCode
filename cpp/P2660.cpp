/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-25 19:16
//	Comment		:	OJ(P2660)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




long long			g_nSum		= 0;
void CountLength(long long nX, long long nY)
{
	if (nX == nY)
	{
		g_nSum += nX * 4;
		return;
	}
	else
	{
		if (nX > nY)
			swap(nX, nY);


		g_nSum += nX * 4 * (nY / nX);

		if (nY % nX != 0)
			CountLength(nX, nY % nX);
	}
}





int main(int argc, char* argv[])
{
	long long 					nInputX;
	long long 					nInputY;

	scanf("%lld%lld", &nInputX, &nInputY);


	CountLength(nInputX, nInputY);

	printf("%lld", g_nSum);
		




		


Exit0:

	return 0;
}