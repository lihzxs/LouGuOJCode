/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-26 15:16
//	Comment		:	OJ(P1211)
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

bool IsTrue(BOOL* pbFlag, int nNum)
{
	while (nNum != 0)
	{
		if (!pbFlag[nNum % 10])
			return false;
		nNum /= 10;
	}
	return true;
}




int main(int argc, char* argv[])
{
	int					nInputN;
	BOOL*				pbFlag			= NULL;
	int					nInputTemp;
	int*				pnSeq			= NULL;
	int					nAns			= 0;
	int					nTempNum1;
	int					nTempNum2;

	scanf("%d", &nInputN);


	pbFlag = (BOOL*)malloc(10 * sizeof(BOOL));
	memset(pbFlag, false, 10 * sizeof(int));
	pnSeq = (int*)malloc(nInputN * sizeof(int));

	

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		pnSeq[i] = nInputTemp;
		pbFlag[nInputTemp] = true;
	}

	for (int i = 0; i < nInputN; i++)
		for (int j = 0; j < nInputN; j++)
			for (int k = 0; k < nInputN; k++)
				for (int l = 0; l < nInputN; l++)
					for (int n = 0; n < nInputN; n++)
					{
						nTempNum1 = pnSeq[l] * pnSeq[i] * 100 +
							pnSeq[l] * pnSeq[j] * 10 + pnSeq[l] * pnSeq[k];
						if (nTempNum1 >= 1000)
							continue;
						nTempNum2 = pnSeq[n] * pnSeq[i] * 100 +
							pnSeq[n] * pnSeq[j] * 10 + pnSeq[n] * pnSeq[k];

						if (nTempNum2 >= 1000)
							continue;

						if (IsTrue(pbFlag, nTempNum1) && IsTrue(pbFlag, nTempNum2) &&
							IsTrue(pbFlag, nTempNum1 + nTempNum2 * 10))
							nAns++;
					}


	printf("%d\n", nAns);

	



		













Exit0:

	return 0;
}