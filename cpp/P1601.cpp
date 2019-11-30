/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-6 23:09
//	Comment		:	OJ(P1255)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


string Add(string szA, string& szB)
{
	if (szA.length() < szB.length())
		swap(szA, szB);
	int			nALen			= szA.length();
	int			nBLen			= szB.length();
	int			nPre			= 0;
	int			nA;
	int			nB;
	while (nALen > 0 || nBLen > 0)
	{
		if (nALen > 0)
		{
			nALen--;
			nA = szA[nALen] - '0';
		}
		else
			nA = 0;
		if (nBLen > 0)
		{
			nBLen--;
			nB = szB[nBLen] - '0';
		}
		else
			nB = 0;
		szA[nALen] = (nA + nB + nPre) % 10 + '0';
		nPre = (nA + nB + nPre) / 10;
	}
	if (nPre > 0)
		szA = "1" + szA;
	return szA;

}



int main(int argc, char* argv[])
{
    string      szInputA;
    string      szInputB;
    
    cin >> szInputA >> szInputB;
    cout << Add(szInputA, szInputB) << endl;


Exit0:

	return 0;
}