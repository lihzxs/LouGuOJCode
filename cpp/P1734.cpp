/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-3 20:10
//	Comment		:	OJ(P1734)
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




int main(int argc, char* argv[])
{
	int				nInputS;
	int*			pnW				= NULL;
	int*			pnBagForm		= NULL;
	int				nTemp			= 0;
	scanf("%d", &nInputS);

	pnW = (int*)malloc(nInputS * sizeof(int));
	pnBagForm = (int*)malloc((nInputS + 1) * sizeof(int));
	memset(pnBagForm, 0, (nInputS + 1) * sizeof(int));

	for (int i = 1; i < nInputS; i++)
	{
		for (int j = 1; j < i; j++)
			if (i % j == 0)
				nTemp += j;
		pnW[i] = nTemp;
		nTemp = 0;
	}


	for (int i = 1; i < nInputS; i++)
		for (int j = nInputS; j >= i; j--)
			pnBagForm[j] = max(pnBagForm[j],
				pnBagForm[j - i] + pnW[i]);


	printf("%d", pnBagForm[nInputS]);

Exit0:
	return 0;
}