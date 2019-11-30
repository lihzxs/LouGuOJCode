/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-13 15:05
//	Comment		:	OJ(P1874)
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
void DFS(int* pnAdd, string& szTemp, int nCount, int nN, int& nAns)
{
	if (nCount == szTemp.length())
	{
		int nC = 0;
		int nSum = 0;
		int nTemp;
		int nPre = 0; 
		for (int i = 0; i < szTemp.length(); i++)
		{
			nTemp = 0;
			if (pnAdd[i])
			{
				nC++;
				nTemp = 0;
				for (int j = nPre; j < i; j++)
					nTemp = nTemp * 10 + szTemp[j];
				nSum += nTemp;
				nPre = i;
			}
		}
		nTemp = 0;
		for (int j = nPre; j < szTemp.length(); j++)
			nTemp = nTemp * 10 + szTemp[j];
		nSum += nTemp;
		if (nSum == nN)
			nAns = min(nAns, nC);
		return;
	}
	pnAdd[nCount] = 1;
	DFS(pnAdd, szTemp, nCount + 1, nN, nAns);
	pnAdd[nCount] = 0;
	DFS(pnAdd, szTemp, nCount + 1, nN, nAns);
}



int main(int argc, char* argv[])
{
	string			szTemp;
	int*			pnAdd					= NULL;
	int				nInputN;
	int				nAns;

	cin >> szTemp >> nInputN;
	pnAdd = (int*)malloc(szTemp.length() * sizeof(int));
	memset(pnAdd, 0, szTemp.length() * sizeof(int));
	nAns = szTemp.length();
	for (int i = 0; i < szTemp.length(); i++)
		szTemp[i] -= '0';
	DFS(pnAdd, szTemp, 1, nInputN, nAns);
	if (nAns == szTemp.length())
		printf("-1");
	else
		printf("%d", nAns);
Exit0:

	return 0;
}