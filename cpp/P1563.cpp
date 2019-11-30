/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-5 14:37
//	Comment		:	OJ(P1563)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int					nTemp;
	int					nNum;
	int					nPreIndex				= 1;
	string				szName;
	pair<int, string>*	ppairItem				= NULL;
	scanf("%d%d", &nInputN, &nInputM);
	ppairItem = new pair<int, string>[nInputN + 1];

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> nTemp >> szName;
		ppairItem[i].first = nTemp;
		ppairItem[i].second = szName;
	}


	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nTemp, &nNum);
		if (ppairItem[nPreIndex].first == nTemp)
		{
			nPreIndex -= nNum;
			if (nPreIndex < 1)
				nPreIndex += nInputN;
		}
		else
		{
			nPreIndex += nNum;
			if (nPreIndex > nInputN)
				nPreIndex -= nInputN;
		}


	}

	cout << ppairItem[nPreIndex].second << endl;




Exit0:
	return 0;
}