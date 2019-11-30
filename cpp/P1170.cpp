/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 15:18
//	Comment		:	OJ(P1170)
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



int CalcGCD(int a, int b)
{
	if (a%b == 0)
		return b;
	return CalcGCD(b, a%b);
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputX1;
	int				nInputY1;
	int				nInputX2;
	int				nInputY2;
	scanf("%d", &nInputN);
	while (nInputN--)
	{
	    scanf("%d%d", &nInputX2, &nInputY2);
		scanf("%d%d", &nInputX1, &nInputY1);
		

		if (nInputX2 == nInputX1 && nInputY2 == nInputY1)
			printf("no\n");
		else if (nInputX2 == nInputX1 + 1 && nInputY2 == nInputY1 + 1)
			printf("no\n");
		else if (nInputX2 == nInputX1 - 1 && nInputY2 == nInputY1 - 1)
			printf("no\n");
		else if (nInputX2 == nInputX1 + 1 && nInputY2 == nInputY1 - 1)
			printf("no\n");
		else if (nInputX2 == nInputX1 - 1 && nInputY2 == nInputY1 + 1)
			printf("no\n");
		else if (nInputX2 == nInputX1 && nInputY2 == nInputY1 + 1)
			printf("no\n");
		else if (nInputX2 == nInputX1 + 1 && nInputY2 == nInputY1)
			printf("no\n");
		else if (nInputX2 == nInputX1 - 1 && nInputY2 == nInputY1)
			printf("no\n");
		else if (nInputX2 == nInputX1 && nInputY2 == nInputY1 - 1)
			printf("no\n");
		else if (nInputX1 == nInputX2 || nInputY1 == nInputY2)
			printf("yes\n");
		else if (CalcGCD(abs(nInputX1 - nInputX2) , abs(nInputY1 - nInputY2)) != 1)
			printf("yes\n");
		else
			printf("no\n");



	}

Exit0:

	return 0;
}