/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-15 19:20
//	Comment		:	OJ(P2628)
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
	string			szTemp;
	int				nInputN;
	int*			pnSeq		= NULL;
	int				nTemp;
	int				nCount		= 0;
	getline(cin, szTemp);
	scanf("%d", &nInputN);
	szTemp = szTemp.substr(0, szTemp.length() - 1);
	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);
	nTemp = -1;
	for (int i = 0; i < nInputN; i++)
	{
		nTemp += pnSeq[i];
		if (nTemp >= szTemp.length())
			nTemp = szTemp.length() - 1;
		if (szTemp[nTemp] == '>' && szTemp[nTemp + 1] == '>' && 
			szTemp[nTemp + 2] == '>')
		{
			while (szTemp[nTemp] == '>')
				nTemp++;
		}
		else if (szTemp[nTemp] == '*' && szTemp[nTemp + 1] == '*' &&
			szTemp[nTemp + 2] == '*')
		{
			nCount = 0;
			while (szTemp[nTemp + nCount] == '*')
				nCount++;
			nTemp -= nCount;
		}
		if (nTemp < 0)
			nTemp = 0;
		if (nTemp >= szTemp.length())
			nTemp = szTemp.length() - 1;
	}

	printf("%d %d\n", nTemp + 1, szTemp.length() - 1 - nTemp);
Exit0:

	return 0;
}