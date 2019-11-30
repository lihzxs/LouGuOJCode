/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-30 11:59
//	Comment		:	OJ(P1802)
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
	int				nInputN;
	int				nInputX;
	int				nInputLoseTemp;
	int				nInputWinTemp;
	int				nInputUseNum;
	long long*		pnBagForm = NULL;

	scanf("%d%d", &nInputN, &nInputX);
	pnBagForm = (long long*)malloc((nInputX + 1) * sizeof(long long));
	memset(pnBagForm, 0, (nInputX + 1) * sizeof(long long));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d", &nInputLoseTemp, &nInputWinTemp, &nInputUseNum);
		for (int j = nInputX; j >= 0; j--)
		{
			if (j >= nInputUseNum)
				pnBagForm[j] = max(pnBagForm[j] + nInputLoseTemp,
					pnBagForm[j - nInputUseNum] + nInputWinTemp);
			else
				pnBagForm[j] = pnBagForm[j] + nInputLoseTemp;
		}
	}

	printf("%lld", (pnBagForm[nInputX] * 5));


Exit0:

	return 0;
}