/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-9 22:32
//	Comment		:	OJ(P1532)
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


int main(int argc, char* argv[])
{
	int					nInputT;
	long long			llNumBig;
	long long			llNumSmall;
	long long			nInputN;
	long long*			llSeq						= NULL;
	int					nCount;
	int					nIndex;
	vector<int>			vecNum;

	llSeq = (long long*)malloc(100000 * sizeof(long long));
	while (cin >> nInputN)
	{
		nCount = 0;
		
		while (true)
		{
			vecNum.clear();
			llSeq[nCount++] = nInputN;
			while (nInputN)
			{
				vecNum.push_back(nInputN % 10);
				nInputN /= 10;
			}
			sort(vecNum.begin(), vecNum.end());
			llNumBig = 0;
			llNumSmall = 0;
			for (int i = 0; i < vecNum.size(); i++)
				llNumBig += vecNum[i] * pow(10, i);
			for (int i = 0; i < vecNum.size(); i++)
				llNumSmall += vecNum[vecNum.size() - 1 - i] * pow(10, i);
			nInputN = llNumBig - llNumSmall;
			nIndex = 0;
			for (int i = 0; i < nCount; i++)
				if (llSeq[i] == nInputN)
				{
					nIndex = i;
					break;
				}
			if (llSeq[nIndex] == nInputN)
			{
				for (int i = nIndex; i < nCount; i++)
					printf("%lld ", llSeq[i]);
				printf("\n");
				break;
			}
		}
	}

Exit0:

	return 0;
}