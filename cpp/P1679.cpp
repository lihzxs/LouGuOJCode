/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-6 22:28
//	Comment		:	OJ(P1679)
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
	int				nInputN;
	int*			pnBagForm				= NULL;
	int*			pnNumList				= NULL;
	scanf("%d", &nInputN);

	pnBagForm = (int*)malloc((nInputN + 1) * sizeof(int));
	pnNumList = (int*)malloc(19 * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		pnBagForm[i] = nInputN;
	pnBagForm[0] = 0;
	for (int i = 1; i <= 18; i++)
		pnNumList[i] = i * i * i * i;


	for (int i = 1; pnNumList[i] <= nInputN; i++)
	{
		for (int j = pnNumList[i]; j <= nInputN; j++)
			pnBagForm[j] = min(pnBagForm[j - pnNumList[i]] + 1, pnBagForm[j]);

	}


	printf("%d", pnBagForm[nInputN]);
Exit0:
	return 0;
}