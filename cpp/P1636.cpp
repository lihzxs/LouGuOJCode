/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-26 15:35
//	Comment		:	OJ(P1636)
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
	int							nStart;
	int							nEnd;
	int							nAns				= 0;
	int*						pnCount				= NULL;

	scanf("%d%d", &nInputN, &nInputM);

	pnCount = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnCount, 0, (nInputN + 1) * sizeof(int));

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		pnCount[nStart]++;
		pnCount[nEnd]++;
	}

	for (int i = 1; i <= nInputN; i++)
		if (pnCount[i] % 2 != 0)
			nAns++;

	if (nAns == 0)
		printf("1");
	else
		printf("%d", nAns / 2);
Exit0:

	return 0;
}