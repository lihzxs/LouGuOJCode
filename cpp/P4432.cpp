/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-9 21:36
//	Comment		:	OJ(P4432)
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


int main(int argc, char* argv[])
{
	int									nInputN;
	int									nInputM;
	string*								pszInputSeq;
	map<char, vector<string> >			mapDir;
	map<char, int >						mapIndex;
	string								szTemp;
	scanf("%d%d", &nInputN, &nInputM);

	pszInputSeq = new string[nInputN];

	for (int i = 0; i < nInputN; i++)
		cin >> pszInputSeq[i];

	sort(pszInputSeq, pszInputSeq + nInputN);

	for (int i = 0; i < nInputN; i++)
		mapDir[pszInputSeq[i][0]].push_back(pszInputSeq[i]);

	for (int i = 0; i < 26; i++)
		if (mapDir.count('a' + i))
		{
			sort(mapDir['a' + i].begin(), mapDir['a' + i].end());
			mapIndex['a' + i] = 0;
		}

	for (int i = 0; i < nInputM; i++)
	{
		cin >> szTemp;
		cout << mapDir[szTemp[0]][mapIndex[szTemp[0]]] << endl;
		mapIndex[szTemp[0]]++;
		if (mapIndex[szTemp[0]] == mapDir[szTemp[0]].size())
			mapIndex[szTemp[0]] = 0;
	}
			






Exit0:

	return 0;
}