/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-23 21:21
//	Comment		:	OJ(P2908)
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



bool IsExist(string& szStr, string& szSubstr)
{
	int			nRecord			= 0;
	for (int i = 0; i < szStr.length(); i++)
	{
		if (szSubstr[nRecord] == szStr[i])
			nRecord++;
	}
	return nRecord == szSubstr.length();
}




int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	BOOL		bIsNotExist		= false;
	int			nAns			= 0;
	int*		pnSeq			= NULL;
	string*		pszName			= NULL;
	string*		pszGoods		= NULL;

	scanf("%d%d", &nInputN, &nInputM);
	pszName = new string[nInputN];
	pszGoods = new string[nInputM];


	for (int i = 0; i < nInputN; i++)
	{
		cin >> pszName[i];
		transform(pszName[i].begin(), pszName[i].end(),
			pszName[i].begin(), ::toupper);
	}
		

	for (int i = 0; i < nInputM; i++)
	{
		cin >> pszGoods[i];
		transform(pszGoods[i].begin(), pszGoods[i].end(),
			pszGoods[i].begin(), ::toupper);
	}
		

	for (int i = 0; i < nInputN; i++)
	{
		for (int j = 0; j < nInputM; j++)
			if (IsExist(pszName[i], pszGoods[j]))
				nAns++;
		printf("%d\n", nAns);
		nAns = 0;
	}









		




Exit0:

	return 0;
}