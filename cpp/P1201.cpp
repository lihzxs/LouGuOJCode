/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-25 23:16
//	Comment		:	OJ(P1201)
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
	ios::sync_with_stdio(false);
	map<string, int>	mapSI;
	int					nInputN;
	int					nMoney;
	int					nNum;
	string				szInput;
	string*				pszName;

	cin >> nInputN;
	pszName = new string[nInputN];

	for (int i = 0; i < nInputN; i++)
	{
		cin >> szInput;
		pszName[i] = szInput;
		mapSI[szInput] = 0;
	}

	for (int i = 0; i < nInputN; i++)
	{
		cin >> szInput;
		cin >> nMoney >> nNum;
		if (nNum == 0)
			mapSI[szInput] += nMoney;
		else
			mapSI[szInput] += nMoney - nMoney % nNum;
		for (int j = 0; j < nNum; j++)
		{
			cin >> szInput;
			mapSI[szInput] -= nMoney / nNum;
		}
	}

	for (int i = 0; i < nInputN; i++)
	{
		cout << pszName[i] << " " << -mapSI[pszName[i]] << endl;
	}











Exit0:

	return 0;
}