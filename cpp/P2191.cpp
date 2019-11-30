/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-20 21:59
//	Comment		:	OJ(P2191)
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

void TrueRight(vector<pair<int, int> >& vLocal, int nN)
{
	int nTemp;
	for (int i = 0; i < vLocal.size(); i++)
	{
		nTemp = vLocal[i].second;
		vLocal[i].second = nN - vLocal[i].first + 1;
		vLocal[i].first = nTemp;
	}
	sort(vLocal.begin(), vLocal.end());
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int**			ppnFlag				= NULL;
	string*			pszMat				= NULL;
	pair<int, int>	prTemp;
	vector<pair<int, int> >	vLocal;
	string			szOutput;
	string			szTemp;
	scanf("%d", &nInputN);



	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szTemp;
		for (int j = 0; j <= szTemp.length(); j++)
		{
			if (szTemp[j] == 'O')
			{
				prTemp.first = i;
				prTemp.second = j + 1;
				vLocal.push_back(prTemp);
			}
		}
	}

	pszMat = new string[nInputN + 1];

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> pszMat[i];
		pszMat[i] = " " + pszMat[i];
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < vLocal.size(); j++)
			szOutput.push_back(pszMat[vLocal[j].first][vLocal[j].second]);
		TrueRight(vLocal, nInputN);
	}

	cout << szOutput;

Exit0:
	return 0;
}