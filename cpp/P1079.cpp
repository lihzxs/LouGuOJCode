/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-6 20:01
//	Comment		:	OJ(P1079)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int Fin(int* pnSet, int nNum)
{
	if (pnSet[nNum] == nNum)
		return pnSet[nNum];
	else
		return pnSet[nNum] =
		Fin(pnSet, pnSet[nNum]);
}




int main(int argc, char* argv[])
{
	string			szInputK;
	string			szInputC;
	int				nCount				= 0;
	int				nDis;

	cin >> szInputK >> szInputC;

	for (int i = 0; i < szInputC.length(); i++)
	{
		if (szInputK[nCount] <= 'Z')
			nDis = szInputK[nCount] - 'A';
		else
			nDis = szInputK[nCount] - 'a';
		if (szInputC[i] <= 'Z')
		{
			if (nDis >= szInputC[i] - 'A')
			{
				szInputC[i] = (26 - (nDis - szInputC[i] + 'A')) % 26 + 'A';
			}
			else
			{
				szInputC[i] = szInputC[i] - nDis;
			}
				
		}
		else
		{
			if (nDis >= szInputC[i] - 'a')
			{
				szInputC[i] = (26 - (nDis - szInputC[i] + 'a')) % 26 + 'a';
			}
			else
			{
				szInputC[i] = szInputC[i] - nDis;
			}
				
		}
		
		nCount++;
		if (nCount == szInputK.length())
			nCount = 0;
	}

	cout << szInputC;









Exit0:
	return 0;
}