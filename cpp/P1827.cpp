/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-9 23:53
//	Comment		:	OJ(P1827)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

void Print(string& szA, string& szB, int nAL,
	int nAR, int nBL, int nBR)
{
	if (nAL >= nAR)
		return;
	if (nBL >= nBR)
		return;
	char cTemp = szB[nBL];
	int nIndex;
	for (int i = nAL; i < nAR; i++)
		if (szA[i] == cTemp)
		{
			nIndex = i;
			break;
		}
	Print(szA, szB, nAL, nIndex, nBL + 1, nBL + nIndex - nAL + 1);
	Print(szA, szB, nIndex + 1, nAR, nBL + nIndex - nAL + 1, nBR);
	cout << cTemp;
}




int main(int argc, char* argv[])
{
	string				szInputA;
	string				szInputB;

	cin >> szInputA >> szInputB;
	Print(szInputA, szInputB, 0, szInputA.length(), 0, szInputB.length());




Exit0:

	return 0;
}