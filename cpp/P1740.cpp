/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-10 22:16
//	Comment		:	OJ(P1740)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int			nInputN;
	string		szTemp;
	string*		pszStr;
	int			nNum;
	int			nY;
	int			nX;
	cin >> nInputN;
	getline(cin, szTemp);
	pszStr = new string[3 * nInputN];
	for (int i = 1; i <= nInputN * 2; i++) 
	{
		getline(cin, szTemp);
		pszStr[i] = " " + szTemp;
	}
	cout << nInputN << endl;
	for (int i = 1; i <= 2 * nInputN + 1; i++) 
	{
		nNum = nInputN + !(i & 1);
		nY = 1 + (i - 1) / 2; 
		nX = nInputN + 1 - i / 2;
		for (int j = 1; j <= nNum; j++)
		{
			if (pszStr[nY++][nX++] == ' ')
				printf("0");
			else
				printf("1");
		}
		printf("\n");
	}

Exit0:

	return 0;
}