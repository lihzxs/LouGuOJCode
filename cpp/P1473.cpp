/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-3 13:49
//	Comment		:	OJ(P1473)
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


void DFS(int nN, int* pnSeq, int nCount)
{
	if (nCount == nN + 1)
	{
		int nSum = 1;
		int nPre = 1;
		for (int i = 2; i <= nN; i++)
		{
			if (pnSeq[i] == 1)
			{
				nSum -= nPre;
				nPre *= 10;
				if (nPre < 0)
					nPre -= i;
				else
					nPre += i;
				nSum += nPre;
			}
			else if (pnSeq[i] == 2)
			{
				nSum += i;
				nPre = i;
			}
			else
			{
				nSum -= i;
				nPre = -i;
			}	
		}
		if (nSum == 0)
		{
			printf("1");
			for (int i = 2; i <= nN; i++)
			{
				if (pnSeq[i] == 1)
					printf(" ");
				if (pnSeq[i] == 2)
					printf("+");
				if (pnSeq[i] == 3)
					printf("-");
				printf("%d", i);
			}
			printf("\n");
		}
		
		return;
	}
		
	for (int i = 1; i <= 3; i++)
	{
		pnSeq[nCount] = i;
		DFS(nN, pnSeq, nCount + 1);
	}
}




int main(int argc, char* argv[])
{
	int			nInputN;
	scanf("%d", &nInputN);
	int*		pnSeq				= NULL;

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));

	DFS(nInputN, pnSeq, 2);

Exit0:
	return 0;
}