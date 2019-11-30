/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-25 16:01
//	Comment		:	OJ(P1192)
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
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;






int main(int argc, char* argv[])
{

	int				nInputN;
	int				nInputK;
	int*			pnSeq			= NULL;

	scanf("%d%d", &nInputN, &nInputK);
	
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputK; i++)
		pnSeq[i] = 1;
	for (int i = nInputK + 1; i <= nInputN; i++)
		pnSeq[i] = 0;



	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputK; j++)
		{
			if (i - j <= 0)
				break;
			pnSeq[i] += pnSeq[i - j];
			pnSeq[i] %= MODNUM;
		}
	}

	printf("%d", pnSeq[nInputN]);


Exit0:

	return 0;
}