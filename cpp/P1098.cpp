/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-30 20:05
//	Comment		:	OJ(P1098)
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
#include <sstream>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	int				nInputP1;
	int				nInputP2;
	int				nInputP3;
	int				nStart;
	int				nEnd;
	int				nTemp;
	string			szInput;
	
	scanf("%d%d%d", &nInputP1, &nInputP2, &nInputP3);
	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] == '-' && i - 1 >= 0 &&
			((isdigit(szInput[i - 1]) && isdigit(szInput[i + 1])) || 
			(islower(szInput[i - 1]) && islower(szInput[i + 1]))) )
		{
			if (szInput[i - 1] + 1 == szInput[i + 1])
				continue;
			else if (szInput[i - 1] >= szInput[i + 1])
				printf("%c", szInput[i]);
			else
			{
				if (nInputP1 == 3)
				{
					for (int j = 0; j < 
						(szInput[i + 1] - szInput[i - 1] - 1) * nInputP2; j++)
						printf("*");
					continue;
				}
				nStart = szInput[i - 1] + 1;
				nEnd = szInput[i + 1] - 1;
				nTemp = 0;
				if (nInputP1 == 2 && !isdigit(szInput[i - 1]))
					nTemp = 'A' - 'a';
				if (nInputP3 == 2)
				{
					for (int j = nEnd; j >= nStart; j--)
					{
						for (int k = 0; k < nInputP2; k++)
							printf("%c", j + nTemp);
					}
				}
				else
				{
					for (int j = nStart; j <= nEnd; j++)
					{
						for (int k = 0; k < nInputP2; k++)
							printf("%c", j + nTemp);
					}
				}


					
				
			}
		}///if (szInput[i] == '-')
		else
			printf("%c", szInput[i]);
	}





Exit0:
	return 0;
}