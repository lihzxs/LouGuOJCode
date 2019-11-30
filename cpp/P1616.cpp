/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-4 16:18
//	Comment		:	OJ(P1616)
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
	int				nInputT;
	int				nInputM;
	int*			pnBagForm		= NULL;
	int				nInputTime;
	int				nInputW;
	scanf("%d%d", &nInputT, &nInputM);

	pnBagForm = (int*)malloc((nInputT + 1) * sizeof(int));
	memset(pnBagForm, 0, (nInputT + 1) * sizeof(int));

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nInputTime, &nInputW);
		for (int j = nInputTime; j <= nInputT; j++)
			pnBagForm[j] = max(pnBagForm[j], 
				pnBagForm[j - nInputTime] + nInputW);
	}

	printf("%d", pnBagForm[nInputT]);





Exit0:
	return 0;
}