/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-25 14:03
//	Comment		:	OJ(P2925)
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

	int				nInputC;
	int				nInputH;
	int				nInputTemp;
	int*			pnBagFrom			= NULL;


	scanf("%d%d", &nInputC, &nInputH);

	pnBagFrom = (int*)malloc((nInputC + 1) * sizeof(int));
	memset(pnBagFrom, 0, (nInputC + 1) * sizeof(int));


	for (int i = 0; i < nInputH; i++)
	{
		scanf("%d", &nInputTemp);

		for (int j = nInputTemp; j <= nInputC; j++)
		{
			pnBagFrom[j] = max(pnBagFrom[j], 
				pnBagFrom[j - nInputTemp] + nInputTemp);
		}
	}

	printf("%d", pnBagFrom[nInputC]);












Exit0:

	return 0;
}