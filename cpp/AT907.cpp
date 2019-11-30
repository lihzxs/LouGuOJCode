
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

int	CountOne(int nN)
{
	int		nCount = 0;
	while (nN)
	{
		if (nN % 2)
			nCount++;
		nN /= 2;
	}
	return nCount;
}

int main(int argc, char* argv[])
{

	int				nInputN;
	int*			pnSeq				= NULL;
	int				nTemp;
	int				nSum				= 0;
	scanf("%d", &nInputN);
	pnSeq = (int*)malloc(1005 * sizeof(int));
	memset(pnSeq, 0, 1005 * sizeof(int));
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		pnSeq[nTemp] = 1;
	}
	for (int i = 1000; i >= 1; i--)
	{
		nSum += pnSeq[i];
		if (nSum == 2)
		{
			printf("%d\n", i);
			break;
		}
			
	}

Exit0:

	return 0;
}