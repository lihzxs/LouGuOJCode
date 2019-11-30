/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 00:38
//	Comment		:	OJ(P2370)
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
#include <bitset>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	int				nN;
	int				nP;
	int				nS;
	int*			pnBag			= NULL;
	pair<int, int>*	prTemp			= NULL;
	scanf("%d%d%d", &nN, &nP, &nS);
	prTemp = new pair<int, int>[nN];
	pnBag = (int*)malloc((nS + 1) * sizeof(int));
	memset(pnBag, 0, (nS + 1) * sizeof(int));

	for (int i = 0; i < nN; i++)
		scanf("%d%d", &prTemp[i].first, &prTemp[i].second);

	sort(prTemp, prTemp + nN);

	for (int i = 0; i < nN; i++)
	{
		for (int j = nS; j >= prTemp[i].first; j--)
		{
			pnBag[j] = max(pnBag[j], pnBag[j - prTemp[i].first] + prTemp[i].second);
			if (pnBag[nS] >= nP)
			{
				printf("%d", prTemp[i].first);
				return 0;
			}
		}
	}

	printf("No Solution!");
	
Exit0:

	return 0;
}