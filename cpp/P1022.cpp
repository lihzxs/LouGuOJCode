/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-27 16:06
//	Comment		:	OJ(P1022)
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
	string				szInput;
	int					nK				= 0;
	int					nB				= 0;
	string				szTemp;
	int					nTemp;
	int					nReCord;
	char				cOut;
	BOOL				bIsLeft			= true;

	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] >= 'a' && szInput[i] <= 'z')
		{
			cOut = szInput[i];
			if (i - 1 >= 0 && szInput[i - 1] == '-')
			{
				if (bIsLeft)
					nK -= 1;
				else
					nK += 1;
			}
			else
			{
				if (bIsLeft)
					nK += 1;
				else
					nK -= 1;
			}
		}
		else if (szInput[i] >= '0' && szInput[i] <= '9')
		{
			for (nReCord = i + 1; nReCord < szInput.length(); nReCord++)
				if (szInput[nReCord] < '0' || szInput[nReCord] > '9')
					break;
			szTemp = szInput.substr(i, nReCord - i);
			nTemp = atoi(szTemp.c_str());
			if (nReCord < szInput.length() &&
				szInput[nReCord] >= 'a' && szInput[nReCord] <= 'z')
			{
				cOut = szInput[nReCord];
				if (i - 1 >= 0 && szInput[i - 1] == '-')
				{
					if (bIsLeft)
						nK -= nTemp;
					else
						nK += nTemp;
				}
				else
				{
					if (bIsLeft)
						nK += nTemp;
					else
						nK -= nTemp;
				}
			}
			else
			{
				if (i - 1 >= 0 && szInput[i - 1] == '-')
				{
					if (bIsLeft)
						nB -= nTemp;
					else
						nB += nTemp;
				}
				else
				{
					if (bIsLeft)
						nB += nTemp;
					else
						nB -= nTemp;
				}
			}
			i = nReCord;
		}
		if (szInput[i] == '=')
			bIsLeft = !bIsLeft;
	}
	if (nB == 0)
		printf("%c=0.000", cOut);
	else
		printf("%c=%.3f", cOut, -nB * 1.0 / nK);
Exit0:

	return 0;
}