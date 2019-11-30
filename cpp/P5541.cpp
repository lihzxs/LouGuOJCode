/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-8 23:11
//	Comment		:	OJ(P5541)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;





int main(int argc, char* argv[])
{

	int					nInputN;
	int*				pnSeq			= NULL;
	int					nCount			= 0;
	int					nAnsMin			= 1000001;
	int					nAnsMax;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);


	sort(pnSeq, pnSeq + nInputN);
	if (pnSeq[nInputN - 2] - pnSeq[0] == nInputN - 2 &&
		pnSeq[nInputN - 1] - pnSeq[nInputN - 2] > 2)
		nAnsMin = 2;
	else if (pnSeq[nInputN - 1] - pnSeq[1] == nInputN - 2 && 
		pnSeq[1] - pnSeq[0] > 2)
		nAnsMin = 2;
	else
	{
		for (int i = 0; i < nInputN; i++)
		{
			for (int j = i + 1; j < nInputN; j++)
				if (pnSeq[j] - pnSeq[i] <= nInputN - 1)
					nCount++;
				else
					break;


			if (nAnsMin > nInputN - nCount - 1)
				nAnsMin = nInputN - nCount - 1;
			nCount = 0;
		}
	}


	nAnsMax = max(pnSeq[nInputN - 2] - pnSeq[0],
		pnSeq[nInputN - 1] - pnSeq[1]) - nInputN + 2;


	printf("%d\n%d", nAnsMin, nAnsMax);







Exit0:

	return 0;
}