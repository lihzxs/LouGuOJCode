/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-13 23:58
//	Comment		:	OJ(P1785)
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
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	int			nX;
	int			nY;
	int			nZ;
	int			nA;
	int			nB;

	scanf("%d%d%d", &nX, &nY, &nZ);

	if (nY <= 0 || nY > 315 || nX > 1800 || nY >= nX || nZ >= 1000 || nZ <= 100)
	{
		printf("Wrong Data");
		return 0;
	}
	else
	{
		if (nZ * 2 <= nX)
		{
			printf("No");
			return 0;
		}
		else
		{
			printf("Yes\n");
			if (nZ >= nX)
				nA = 1;
			else
				nA = 2;
			if (nA * int(nZ * 0.33) + nY >= 315)
				printf("Great");
			else if (nA * int(nZ * 0.5) + nY >= 315)
				printf("Eh..\nOK");
			else if (nZ * nA + nY >= 315)
				printf("Oh..\nOh..\nYes , If he can get 5-star.");
			else
				printf("No\nNo\nNo\n%d", int(nZ * nA * 0.5) + nY);
		}
	}

		


Exit0:

	return 0;
}