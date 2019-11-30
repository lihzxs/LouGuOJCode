/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-6 00:22
//	Comment		:	OJ(P1467)
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

bool Check(vector<int>& vecNum)
{
	int nStart = 1;
	int				pnVis[10];
	memset(pnVis, 0, 10 * sizeof(int));
	for (int i = 1; i < vecNum.size(); i++)
	{
		if (pnVis[vecNum[nStart]] || vecNum[nStart] == 0)
			return false;
		pnVis[vecNum[nStart]]++;
		nStart = (nStart + vecNum[nStart]) % (vecNum.size() - 1);
		if (nStart == 0)
			nStart = vecNum.size() - 1;
	}
	if (nStart != 1)
		return false;
	else
		return true;
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nTemp;
	vector<int>		vecNum;
	scanf("%d", &nInputN);
	while (true)
	{
		nInputN++;
		nTemp = nInputN;
		vecNum.push_back(0);
		while (nTemp)
		{
			vecNum.push_back(nTemp % 10);
			nTemp /= 10;
		}
		int i = 1;
		int j = vecNum.size() - 1;
		while (i < j)
		{
			swap(vecNum[i], vecNum[j]);
			i++;
			j--;
		}

		if (Check(vecNum))
		{
			printf("%d", nInputN);
			return 0;
		}
		vecNum.clear();
	}

Exit0:
	return 0;
}