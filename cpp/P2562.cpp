/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-27 23:57
//	Comment		:	OJ(P2562)
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


bool StringJudge(string& szTemp)
{
	for (int i = 0; i < szTemp.length() - 1; i++)
	{
		if (szTemp[i] != szTemp[i + 1])
			return false;
	}
	return true;
}


string	Precess(string& szTemp)
{
	if (StringJudge(szTemp))
	{
		if (szTemp[0] == '0')
			return "A";
		else
			return "B";
	}
	else
	{
		string		szTemp1			= szTemp.substr(0,szTemp.length() / 2);
		string		szTemp2			= szTemp.substr(szTemp.length() / 2, szTemp.length());
		return "C" + Precess(szTemp1) + Precess(szTemp2);

	}
}



int main(int argc, char* argv[])
{
	string			szInput;
	cin >> szInput;
	cout << Precess(szInput) << endl;

Exit0:

	return 0;
}