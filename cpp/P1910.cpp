/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-26 21:27
//	Comment		:	OJ(P1910)
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
	int							nInputN;
	int							nInputM;
	int							nInputX;
	int							nInputA;
	int							nInputB;
	int							nInputC;
	int**						ppnBagFrom				= NULL;

	scanf("%d%d%d", &nInputN, &nInputM, &nInputX);

	ppnBagFrom = (int**)malloc((nInputX + 1) * sizeof(int*));

	for (int i = 0; i < nInputX + 1; i++)
	{
		ppnBagFrom[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnBagFrom[i], 0, (nInputM + 1) * sizeof(int));
	}

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d", &nInputA, &nInputB, &nInputC);
		for (int j = nInputM; j >= nInputB; j--)
			for (int k = nInputX; k >= nInputC; k--)
				ppnBagFrom[k][j] = max(ppnBagFrom[k][j],
					ppnBagFrom[k - nInputC][j - nInputB] + nInputA);
	}


	printf("%d", ppnBagFrom[nInputX][nInputM]);


		




Exit0:

	return 0;
}