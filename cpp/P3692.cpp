/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-1 20:05
//	Comment		:	OJ(P3692)
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



int main(int argc, char* argv[])
{

	int				nInputT;
	int				nInputN;
	int				nId					= 0;
	int				nPow				= 1;
	int				nCount				= 0;
	string			szKey;
	string			szId;
	string			szType;
	string*			pszKey				= NULL;
	cin >> nInputT;
	cin >> nInputN;
	cin >> szKey;
	pszKey = new string[nInputN];
	for (int i = 0; i < nInputN; i++)
	{
		if (szKey[i] == 'A')
			pszKey[i] = "1000";
		if (szKey[i] == 'B')
			pszKey[i] = "0100";
		if (szKey[i] == 'C')
			pszKey[i] = "0010";
		if (szKey[i] == 'D')
			pszKey[i] = "0001";
	}





	while (nInputT--)
	{
		cin >> szId;
		cin >> szType;
		for (int i = szId.length() - 1; i >= 0; i--)
		{
			nId += (szId[i] - '0') * nPow;
			nPow *= 2;
		}
		if (nId == 0 || nId > 10000)
		{
			printf("Wrong ID\n\n");
			for (int i = 0; i < nInputN; i++)
				cin >> szKey;
		}
		else   
		{
			printf("ID: %d\n", nId);
			if (szId[szId.length() - 1] == szType[1] && 
				szType[0] != szType[1])
				printf("Type Correct\n");
			else
				printf("Type Incorrect\n");
			for (int i = 0; i < nInputN; i++)
			{
				cin >> szKey;
				if (pszKey[i] == szKey)
					nCount++;
			}
			printf("%.1f\n\n", nCount * 1.0 / nInputN * 100);

			
		}
		nCount = 0;
		nId = 0;
		nPow = 1;

	}



Exit0:

	return 0;
}