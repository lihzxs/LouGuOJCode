/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-17 20:56
//	Comment		:	OJ(P4415)
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

void DFS(string szStr, 
	map<string, set<string> >& mpSt, map<string, long long>& mpSize)
{
	for (auto iter = mpSt[szStr].begin(); iter != mpSt[szStr].end(); iter++)
	{
		DFS(*iter, mpSt, mpSize);
		mpSize[szStr] += mpSize[*iter];
	}
}


void OutPut(string szStr, int nT,
	map<string, set<string> >& mpSt, map<string, long long>& mpSize)
{
	if (mpSt[szStr].size() == 0)
	{
		printf("  %s %lld\n", szStr.c_str(), mpSize[szStr]);
		return;
	}
	int nF = 1;
	for (auto iter = mpSt[szStr].begin(); iter != mpSt[szStr].end(); iter++)
	{
		if (mpSize[*iter] >= nT)
			nF = 0;
	}
	if (nF)
		printf("+ %s %lld\n", szStr.c_str(), mpSize[szStr]);
	else
	{
		printf("- %s %lld\n", szStr.c_str(), mpSize[szStr]);
		for (auto iter2 = mpSt[szStr].begin(); iter2 != mpSt[szStr].end(); iter2++)
			OutPut(*iter2, nT, mpSt, mpSize);
	}

}

int main(int argc, char* argv[])
{
	int							nN;
	long long					nVal;
	long long					nT;
	string						szTemp;
	map<string, set<string> >	mpSt;
	map<string, long long>		mpSize;
	string						szFa;
	string						szSub;

	scanf("%d", &nN);

	for (int i = 1; i <= nN; i++)
	{
		cin >> szTemp >> nVal;
		szFa = "//";
		for (int i = 0; i < szTemp.length(); i++)
		{
			if (szTemp[i] == '/')
			{
				szSub = szTemp.substr(0, i + 1);
				mpSt[szFa].insert(szSub);
				szFa = szSub;
			}
		}

		mpSize[szFa] += nVal;
	}
	scanf("%lld", &nT);
	DFS("//", mpSt, mpSize);
	OutPut(*(mpSt["//"].begin()), nT, mpSt, mpSize);

Exit0:

	return 0;
}