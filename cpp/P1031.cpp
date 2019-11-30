/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-25 22:10
//	Comment		:	OJ(P1031)
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
	int					nInputN;
	int*				pnSeq			= NULL;
	int					nSum			= 0;
	int					nAns			= 0;
	
	scanf("%d", &nInputN);
	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		nSum += pnSeq[i];
	}

	nSum /= nInputN;

	for (int i = 0; i < nInputN; i++)
		pnSeq[i] -= nSum;

	for (int i = 0; i < nInputN - 1; i++)
	{
		if (pnSeq[i] != 0)
		{
			pnSeq[i + 1] += pnSeq[i];
			nAns++;
		}
	}


	printf("%d", nAns);


		


Exit0:

	return 0;
}