/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-28 20:23
//	Comment		:	OJ(P1305)
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



void PrintTree(map<int, pair<int, int> >& mapTree, int nRoot)
{
	if (nRoot == '*' - 'a')
		return;
	printf("%c", nRoot + 'a');

	PrintTree(mapTree, mapTree[nRoot].first);
	PrintTree(mapTree, mapTree[nRoot].second);
}






int main(int argc, char* argv[])
{
	int							nInputN;
	string						szInput;
	int							nRoot;
	map<int, pair<int, int> >	mapTree;

	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		cin >> szInput;
		if (i == 0)
			nRoot = szInput[0] - 'a';
		mapTree[szInput[0] - 'a'].first = szInput[1] - 'a';
		mapTree[szInput[0] - 'a'].second = szInput[2] - 'a';
	}

	PrintTree(mapTree, nRoot);
Exit0:

	return 0;
}