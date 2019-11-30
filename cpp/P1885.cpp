/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-14 22:45
//	Comment		:	OJ(P1885)
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
	int				nInputN;
	string			szTemp;
	string			szO;
	int				nStart			= 4;
	int				nTemp			= 3;
	scanf("%d", &nInputN);
	szTemp = "moo";
	szO = "ooo";

	if (nInputN <= 3)
	{
		if (nInputN == 1)
			printf("m");
		else
			printf("o");
	}
	else
	{
		while (nTemp <= nInputN)
		{
			nTemp = nTemp * 2 + nStart;
			nStart++;
		}
		nStart--;
		while (nTemp > 0)
		{
			nTemp = (nTemp - nStart) / 2;
			if (nInputN > nTemp)
			{
				if (nInputN <= nTemp + nStart)
				{
					if (nInputN == nTemp + 1)
						printf("m");
					else
						printf("o");
					return 0;
				}
				else
					nInputN = nInputN - (nTemp + nStart);
			}
			nStart--;
		}

	}


Exit0:

	return 0;
}