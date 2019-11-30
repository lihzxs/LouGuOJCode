/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 23:47
//	Comment		:	OJ(P1960)
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

void Ans(string& szTemp, int nIndex, int& nCount, double& fAns)
{
	char cTemp = szTemp[nCount++];
	if (cTemp == '0')
		fAns += pow(2, 2 * nIndex);
	else if(cTemp == '2')
	{
		Ans(szTemp, nIndex - 1, nCount, fAns);
		Ans(szTemp, nIndex - 1, nCount, fAns);
		Ans(szTemp, nIndex - 1, nCount, fAns);
		Ans(szTemp, nIndex - 1, nCount, fAns);
	}
}

int main(int argc, char* argv[])
{
	int					nInputK;
	int					nCount = 0;
	double				fAns;
	string				szTemp;

	cin >> nInputK >> szTemp;
	Ans(szTemp, nInputK, nCount, fAns);
	printf("%.0f", fAns);

Exit0:
	return 0;
}