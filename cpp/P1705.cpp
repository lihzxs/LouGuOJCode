/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-11 23:10
//	Comment		:	OJ(P1705)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int						nInputM;
	int						nInputR;
	int						nInputN;
	int*					pnSeq				= NULL;
	int**					ppnBagForm			= NULL;
	int						nAns				= 0;
	int						nSum				= 0;
	scanf("%d%d%d", &nInputM, &nInputR, &nInputN);

	pnSeq = (int*)malloc((nInputM + 1) * sizeof(int));

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d", pnSeq + i);
		nSum += pnSeq[i];
	}
	ppnBagForm = (int**)malloc((nInputR + 1) * sizeof(int*));

	for (int i = 0; i <= nInputR; i++)
	{
		ppnBagForm[i] = (int*)malloc((nSum + 1) * sizeof(int));
		memset(ppnBagForm[i], 0, (nSum + 1) * sizeof(int));
	}

	ppnBagForm[0][0] = 1;

	for (int i = 0; i < nInputM; i++)
	{
		for (int j = nInputR; j >= 1; j--)
		{
			for (int k = pnSeq[i]; k <= nSum; k++)
				ppnBagForm[j][k] += ppnBagForm[j - 1][k - pnSeq[i]];
		}
	}

	for (int i = nInputN + 1; i <= nSum; i++)
		nAns += ppnBagForm[nInputR][i];


	printf("%d", nAns);
		
Exit0:

	return 0;
}