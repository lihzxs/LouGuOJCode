/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-26 00:09
//	Comment		:	OJ(P3864)
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
	ios::sync_with_stdio(false);
	char			cDir[10][3];
	char			cTemp;
	string			szNum;
	string			szTemp;
	map<char, int>	mpFlag;
	int				nCount		= 0;
	mpFlag['A'] = mpFlag['B'] = mpFlag['C'] = 2;
	mpFlag['D'] = mpFlag['E'] = mpFlag['F'] = 3;
	mpFlag['G'] = mpFlag['H'] = mpFlag['I'] = 4;
	mpFlag['J'] = mpFlag['K'] = mpFlag['L'] = 5;
	mpFlag['M'] = mpFlag['N'] = mpFlag['O'] = 6;
	mpFlag['P'] = mpFlag['R'] = mpFlag['S'] = 7;
	mpFlag['T'] = mpFlag['U'] = mpFlag['V'] = 8;
	mpFlag['W'] = mpFlag['X'] = mpFlag['Y'] = 9;

	cin >> szNum;
	bool bIsPrint = false;
	for (int i = 0; i < 4617; i++)
	{
		cin >> szTemp;
		if (szNum.length() != szTemp.length())
			continue;
		int j;
		for (j = 0; j < szTemp.length(); j++)
		{
			if (mpFlag[szTemp[j]] != szNum[j] - '0')
				break;
		}
		if (j == szTemp.length())
		{
			bIsPrint = true;
			cout << szTemp << endl;
		}
			
	}
	if (!bIsPrint)
		cout << "NONE";
Exit0:

	return 0;
}