/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-4 22:20
//	Comment		:	OJ(P1964)
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
	int								nInputM;
	int								nInputN;
	int*							pnBagForm			= NULL;
	map<string, pair<int, int> >	mapThing;
	string							szInput;
	int								nInputA;
	int								nInputB;
	int								nInputC;
	scanf("%d%d", &nInputM, &nInputN);

	nInputM = 21 - nInputM;

	pnBagForm = (int*)malloc((nInputM + 1) * sizeof(int));
	memset(pnBagForm, 0, (nInputM + 1) * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		cin >> nInputA >> nInputB >> nInputC >> szInput;
		mapThing[szInput].first = nInputB;
		if (mapThing[szInput].second + nInputA > nInputC)
			mapThing[szInput].second = nInputC;
		else
			mapThing[szInput].second += nInputA;
	}

	for (map<string, pair<int, int> >::iterator iter = mapThing.begin();
		iter != mapThing.end(); iter++)
	{
		for (int j = nInputM; j >= 1; j--)
		{
			pnBagForm[j] = max(pnBagForm[j], pnBagForm[j - 1] +
				(*iter).second.first * (*iter).second.second);
		}
	}

	printf("%d", pnBagForm[nInputM]);

Exit0:
	return 0;
}