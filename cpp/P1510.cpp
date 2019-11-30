/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-19 23:20
//	Comment		:	OJ(P1510)
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
	int					nInputV;
	int					nInputN;
	int					nInputC;
	int*				pnBagForm				= NULL;
	int					nV;
	int					nC;
	scanf("%d%d%d", &nInputV, &nInputN, &nInputC);

	pnBagForm = (int*)malloc((nInputC + 1) * sizeof(int));
	memset(pnBagForm, 0, (nInputC + 1) * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nV, &nC);
		for (int j = nInputC; j >= nC; j--)
			pnBagForm[j] = max(pnBagForm[j], pnBagForm[j - nC] + nV);
	}

	if (pnBagForm[nInputC] < nInputV)
		printf("Impossible");
	else
	{
		for (int i = 1; i <= nInputC; i++)
		{
			if (pnBagForm[i] >= nInputV)
			{
				printf("%d", nInputC - i);
				return 0;
			}
		}
	}



Exit0:
	return 0;
}