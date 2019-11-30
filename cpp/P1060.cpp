/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-29 21:23
//	Comment		:	OJ(P1060)
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
	int				nMoney;
	int				nInputN;
	int				nInputV;
	int				nInputS;
	int*			pnBagForm			= NULL;
	scanf("%d%d", &nMoney, &nInputN);


	pnBagForm = (int*)malloc((nMoney + 1) * sizeof(int));
	memset(pnBagForm, 0, (nMoney + 1) * sizeof(int));
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nInputV, &nInputS);
		nInputS = nInputS * nInputV;
		for (int j = nMoney; j >= nInputV; j--)
			pnBagForm[j] = max(pnBagForm[j], pnBagForm[j - nInputV] + nInputS);
	}

	printf("%d", pnBagForm[nMoney]);


Exit0:

	return 0;
}