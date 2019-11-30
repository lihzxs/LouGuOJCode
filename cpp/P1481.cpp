/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-30 23:30
//	Comment		:	OJ(P1481)
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
	string				szInput[2005];
	string				szLink[2005];
	int					nInputN;
	int					nCount			= 0;
	int					nAns			= 0;
	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
		cin >> szInput[i];



	for (int i = 0; i < nInputN; i++)
	{
		
		if (nCount == 0)
			szLink[nCount++] = szInput[i];
		else
		{
			for (; nCount >= 1; nCount--)
			{
				if (szLink[nCount - 1] ==
					szInput[i].substr(0, szLink[nCount - 1].length()))
				{
					szLink[nCount] = szInput[i];
					nCount++;
					break;
				}
					
			}
		}
		nAns = max(nAns, nCount);
	}

	printf("%d", nAns);



Exit0:
	return 0;
}