/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-14 23:18
//	Comment		:	OJ(P1994)
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
	int				nCountC		= 0;
	int				nCountH		= 0;
	int				nCountO		= 0;
	int				nTemp		= 0;
	string			szInput;

	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] == 'C')
		{
			i++;
			nTemp = 0;
			while (szInput[i] >= '0' && szInput[i] <= '9')
			{
				nTemp = nTemp * 10 + szInput[i] - '0';
				i++;
			}
			if (nTemp == 0)
				nTemp = 1;
			nCountC += nTemp;
			i--;
		}
		if (szInput[i] == 'H')
		{
			i++;
			nTemp = 0;
			while (szInput[i] >= '0' && szInput[i] <= '9')
			{
				nTemp = nTemp * 10 + szInput[i] - '0';
				i++;
			}
			if (nTemp == 0)
				nTemp = 1;
			nCountH += nTemp;
			i--;

		}
		if (szInput[i] == 'O')
		{
			i++;
			nTemp = 0;
			while (szInput[i] >= '0' && szInput[i] <= '9')
			{
				nTemp = nTemp * 10 + szInput[i] - '0';
				i++;
			}
			if (nTemp == 0)
				nTemp = 1;
			nCountO += nTemp;
			i--;
		}
	}
	if (nCountH % 2 == 1 || (nCountH / 2 + nCountO) % 2 != 0)
	{
		nCountC *= 2;
		nCountO *= 2;
		nCountH *= 2;
	}
	printf("%d %d", nCountC, nCountH / 2);


Exit0:

	return 0;
}