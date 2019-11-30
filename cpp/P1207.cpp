/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-28 21:14
//	Comment		:	OJ(P1207)
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

bool IsTractsNum(const string& szNum)
{
	int		i;
	int		j;
	i = 0;
	j = szNum.length() - 1;
	while (i < j)
	{
		if (szNum[i] != szNum[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int main(int argc, char* argv[])
{
	int							nInputN;
	int							nInputS;
	int							nCount			= 0;
	string						szTemp;
	int							nTemp;

	scanf("%d%d", &nInputN, &nInputS);

	while (nInputN)
	{
		nInputS++;
		szTemp = to_string(nInputS);
		if (IsTractsNum(szTemp))
			nCount++;

		for (int i = 2; i < 10; i++)
		{
			szTemp = "";
			nTemp = nInputS;
			while (nTemp)
			{
				szTemp += nTemp % i;
				nTemp /= i;
			}

			if (IsTractsNum(szTemp))
				nCount++;
			if (nCount == 2)
			{
				printf("%d\n", nInputS);
				nInputN--;
				nCount = 0;
				break;
			}
			
		}
		nCount = 0;
	}


Exit0:

	return 0;
}