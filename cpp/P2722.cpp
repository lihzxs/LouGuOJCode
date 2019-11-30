/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 23:09
//	Comment		:	OJ(P2722)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;








int main(int argc, char* argv[])
{

	int				nInputM;
	int				nInputN;
	int				nInputPoint;
	int				nInputTime;
	int*			pnBagFrom			= NULL;

	scanf("%d%d", &nInputM, &nInputN);

	pnBagFrom = (int*)malloc((nInputM + 1) * sizeof(int));

	memset(pnBagFrom, 0, (nInputM + 1) * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nInputPoint, &nInputTime);
			for (int j = nInputTime; j <= nInputM; j++)
				pnBagFrom[j] = max(pnBagFrom[j],
					pnBagFrom[j - nInputTime] + nInputPoint);
	}

	printf("%d", pnBagFrom[nInputM]);












Exit0:

	return 0;
}