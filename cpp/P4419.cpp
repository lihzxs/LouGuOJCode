/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-27 15:35
//	Comment		:	OJ(P4419)
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

	int					nInputN;
	int					nInputTemp;
	int					nSum					= 0;
	int					nX;
	int					nGreater				= 0;
	int					nless					= 0;
	int*				pnSeq					= NULL;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(13 * sizeof(int));
	memset(pnSeq, 0, 13 * sizeof(int));
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		nSum += nInputTemp;
		pnSeq[nInputTemp]++;
	}
	nX = 21 - nSum;

	for (int i = 1; i <= 12; i++)
	{
		if (i == 10)
		{
			if (i > nX)
				nGreater += 16 - pnSeq[i];
			else
				nless += 4 - pnSeq[i];
		}
		else
		{
			if (i > nX)
				nGreater += 4 - pnSeq[i];
			else
				nless += 4 - pnSeq[i];
		}
	}

	if (nGreater >= nless)
		printf("DOSTA");
	else
		printf("VUCI");

		







Exit0:

	return 0;
}