/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-30 16:05
//	Comment		:	OJ(P1061)
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
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

char Check(string& szTemp, int nN, int nT, int nIndex)
{
	if (nIndex == 0)
		return -1;
	char	cTemp;
	cTemp = szTemp[nIndex];
	if (cTemp + 1 > 96 + nT - nN + 1 + nIndex)
	{
		cTemp = Check(szTemp, nN, nT, nIndex - 1);
		if (cTemp == -1)
			return -1;
		szTemp[nIndex] = cTemp + 1;
		return szTemp[nIndex];
	}
	else
	{
		szTemp[nIndex] = cTemp + 1;
		return szTemp[nIndex];
	}
}



int main(int argc, char* argv[])
{
	int			nS;
	int			nT;
	int			nW;
	string		szInput;

	cin >> nS >> nT >> nW >> szInput;

	for (int i = 0; i < 5; i++)
	{
		if (Check(szInput, nW, nT, nW - 1) == -1)
			break;
		cout << szInput << endl;
	}

Exit0:

	return 0;
}