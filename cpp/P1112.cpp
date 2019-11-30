/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-7 16:06
//	Comment		:	OJ(P1112)
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
	int				nInputN;
	int				nInputM;

	int				nStart;
	int				nEnd;

	int				nC;

	int				nTemp;
	int				nCount;
	int*			mpCount;
	string			szTemp;
	mpCount = (int*)malloc(10000001 * sizeof(int));
	memset(mpCount, 0, 10000001 * sizeof(int));

	scanf("%d%d%d%d%d", &nInputN, &nInputM, &nStart, &nEnd, &nC);


	for (int i = nInputN; i <= nInputM; i++)
	{
		for (int j = 1; j < i; j++)
			for (int k = 0; k < i; k++)
			{
				if (j != k)
				{
					nTemp = 0;
					nCount = 0;
					while (nTemp <= nEnd)
					{
						if (nCount % 2 == 0)
						{
							nTemp = nTemp * i + j;
							nCount++;
						}
						else
						{
							nTemp = nTemp * i + k;
							nCount++;
						}
						if (nTemp >= nStart && nTemp <= nEnd)
							mpCount[nTemp]++;
					}
				}
			}
	}

	for (int i = nStart; i <= nEnd; i++)
		if (mpCount[i] == nC)
			printf("%d\n", i);

Exit0:

	return 0;
}