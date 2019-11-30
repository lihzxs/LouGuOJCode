/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-1 16:48
//	Comment		:	OJ(P1042)
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

	char		cInput;
	int			nCount11W			= 0;
	int			nCount11L			= 0;
	int			nCount21W			= 0;
	int			nCount21L			= 0;
	string		szOutputTemp		= "";
	string		sz11Output			= "";
	string		sz21Output			= "";


	while (scanf("%c", &cInput))
	{
		if (cInput == 'E')
			break;
		if (cInput == 'W')
		{
			nCount11W++;
			nCount21W++;
		}
		if (cInput == 'L')
		{
			nCount11L++;
			nCount21L++;
		}
		if (nCount11L > 10 || nCount11W > 10)
		{
			if (abs(nCount11L - nCount11W) >= 2)
			{
				szOutputTemp = to_string(nCount11W) + ":" + 
					to_string(nCount11L) + "\n";
				//sprintf(&szOutputTemp[0], "%d:%d", nCount11W, nCount11L);
				sz11Output += szOutputTemp;
				nCount11L = 0;
				nCount11W = 0;
			}
		}
		if (nCount21L > 20 || nCount21W > 20)
		{
			if (abs(nCount21L - nCount21W) >= 2)
			{
				//sprintf(&szOutputTemp[0], "%d:%d", nCount21W, nCount21L);
				szOutputTemp = to_string(nCount21W) + ":" +
					to_string(nCount21L) + "\n";
				sz21Output += szOutputTemp;
				nCount21W = 0;
				nCount21L = 0;
			}
		}
	}

	if (nCount11L > 0 || nCount11W > 0)
	{
		szOutputTemp = to_string(nCount11W) + ":" +
			to_string(nCount11L) + "\n";
		//sprintf(&szOutputTemp[0], "%d:%d", nCount11W, nCount11L);
		sz11Output += szOutputTemp;
	}
	if (nCount21L > 0 || nCount21W > 0)
	{
		szOutputTemp = to_string(nCount21W) + ":" +
			to_string(nCount21L) + "\n";
		//sprintf(&szOutputTemp[0], "%d:%d", nCount21W, nCount21L);
		sz21Output += szOutputTemp;
	}
	if (nCount11L == 0 && nCount11W == 0)
	{
		szOutputTemp = "0:0\n";
		sz11Output += szOutputTemp;
	}
	if (nCount21L == 0 && nCount21W == 0)
	{
		szOutputTemp = "0:0\n";
		sz21Output += szOutputTemp;
	}
	
	cout << sz11Output << endl;
	//cout << endl;
	cout << sz21Output << endl;

Exit0:

	return 0;
}