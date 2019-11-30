/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-26 22:26
//	Comment		:	OJ(P1507)
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
	int					nInputM;

	int					nInputN;

	int					nInputItemV;
	int					nInputItemM;
	int					nInputItemK;
	int**				ppnBagFrom				= NULL;

	scanf("%d%d", &nInputV, &nInputM);
	scanf("%d", &nInputN);

	ppnBagFrom = (int**)malloc((nInputV + 1) * sizeof(int*));
	for (int i = 0; i < nInputV + 1; i++)
	{
		ppnBagFrom[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnBagFrom[i], 0, (nInputM + 1) * sizeof(int));

	}


	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d", &nInputItemV, &nInputItemM, &nInputItemK);
		for (int j = nInputV; j >= nInputItemV; j--)
			for (int k = nInputM; k >= nInputItemM; k--)
			{
				ppnBagFrom[j][k] = max(ppnBagFrom[j][k],
					ppnBagFrom[j - nInputItemV][k - nInputItemM] + nInputItemK);
			}
	}

	printf("%d", ppnBagFrom[nInputV][nInputM]);




Exit0:

	return 0;
}