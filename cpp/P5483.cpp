
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-22 23:25
//	Comment		:	OJ(P5483)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{

	ios::sync_with_stdio(false);

	int					nInputN;
	int					nMax = 0;
	int					nInputM;
	int					nMaxLine				= 0;
	int					pnReCord[105];
	string				szTemp;
	string				szName;
	string				pszOutput[105];
	int					nCount					= 0;

	pszOutput[0] = "";
	cin >> nInputN;
	while (nInputN--)
	{
		nMax = 0;
		cin >> nInputM >> szName;
		nMaxLine = max(nMaxLine, nInputM);
		for (int i = 1; i <= nInputM; i++)
		{
			cin >> szTemp;
			nCount = 0;
			for (int j = 0; j < szTemp.length(); j++)
				if (szTemp[j] == ',')
					nCount++;
			pnReCord[i] = nCount;
			nMax = max(nCount, nMax);
			pszOutput[i] += szTemp;
		}
		for (int i = 1; i <= nInputM; i++)
		{
			for (int j = 0; j < nMax - pnReCord[i]; j++)
				pszOutput[i] += ',';
		}
		szTemp.clear();
		for (int i = 0; i < nMax; i++)
			szTemp.push_back(',');
		for (int i = nInputM + 1; i <= 100; i++)
			pszOutput[i] += szTemp;
		pszOutput[0] += szName + szTemp;
		if (nInputN)
			for (int i = 0; i <= 100; i++)
				pszOutput[i] += ",";

	}


	for (int i = 0; i <= nMaxLine; i++)
		cout << pszOutput[i] << endl;




Exit0:

	return 0;
}