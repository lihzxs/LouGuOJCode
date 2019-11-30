/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-26 23:47
//	Comment		:	OJ(P1146)
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
	int				nN;
	int*			pnSeq			= NULL;
	scanf("%d", &nN);
	printf("%d\n", nN);

	pnSeq = (int*)malloc((nN + 1) * sizeof(int));
	memset(pnSeq, 0, (nN + 1) * sizeof(int));

	for (int i = 1; i <= nN; i++)
	{
		for (int j = 1; j <= nN; j++)
		{
			if (j == i)
			{
				printf("%d", pnSeq[j]);
				continue;
			}
				
			if (pnSeq[j])
				pnSeq[j] = 0;
			else
				pnSeq[j] = 1;
			printf("%d", pnSeq[j]);
		}
		printf("\n");
	}
		



Exit0:
	return 0;
}