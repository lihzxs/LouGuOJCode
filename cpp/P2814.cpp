/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-24 17:31
//	Comment		:	OJ(P2814)
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

string Fin(map<string, string>& mpSztoSz, string szTemp)
{
	if (mpSztoSz[szTemp] == szTemp)
		return mpSztoSz[szTemp];
	else
		return mpSztoSz[szTemp] =
		Fin(mpSztoSz, mpSztoSz[szTemp]);
}


int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	string				szTemp;
	string				szPre;
	map<string, string>	mpSztoSz;
	char				cTemp;

	cin >> cTemp;

	while (cTemp != '$')
	{
		cin >> szTemp;
		if (cTemp == '#')
		{
			szPre = szTemp;
			if (!mpSztoSz.count(szTemp))
				mpSztoSz[szTemp] = szTemp;
		}
		else if (cTemp == '+')
			mpSztoSz[szTemp] = szPre;
		else
			cout << szTemp << " " << Fin(mpSztoSz, szTemp) << endl;
		cin >> cTemp;
	}



Exit0:
	return 0;
}