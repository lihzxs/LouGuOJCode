/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-13 23:41
//	Comment		:	OJ(P1757)
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
	int							nInputN;
	int							nInputM;
	map<int, pair<int, int>>	mpThing;
	int							nInputA;
	int							nInputB;
	int							nInputC;
	int*						pnBagFrom				= NULL;
	scanf("%d%d", &nInputN, &nInputM);

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nInputA, &nInputB, &nInputC);
		if (nInputA > nInputN)
			continue;
		if (mpThing.count(nInputC))
		{
			if (mpThing[nInputC].second * 1.0 / mpThing[nInputC].first <
				nInputB * 1.0 / nInputA)
			{
				mpThing[nInputC].first = nInputA;
				mpThing[nInputC].second = nInputB;
			}
		}
		else
		{
			mpThing[nInputC].first = nInputA;
			mpThing[nInputC].second = nInputB;
		}
	}

	pnBagFrom = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnBagFrom, 0, (nInputN + 1) * sizeof(int));
	for (int i = 1; i <= 100; i++)
	{
		if (mpThing.count(i))
		{
			for (int j = nInputN; j >= mpThing[i].first; j--)
				pnBagFrom[j] = max(pnBagFrom[j],
					pnBagFrom[j - mpThing[i].first] + mpThing[i].second);
		}
	}

	printf("%d", pnBagFrom[nInputN]);





Exit0:

	return 0;
}