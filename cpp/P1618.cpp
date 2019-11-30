/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-22 15:26
//	Comment		:	OJ(P1618)
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
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

typedef struct SScore
{
	int			nId;
	int			nScore;
}SScore;

bool Cmp(const SScore sFirst, const SScore sSecond)
{
	if (sFirst.nScore == sSecond.nScore)
		return sFirst.nId < sSecond.nId;
	return sFirst.nScore > sSecond.nScore;

}






int main(int argc, char* argv[])
{
	BOOL*			pbyFlag			= NULL;
	BOOL			bIsRight		= true;
	BOOL			bIsPrint		= false;
	int				nInputA;
	int				nInputB;
	int				nInputC;

	scanf("%d%d%d", &nInputA, &nInputB, &nInputC);

	pbyFlag = (BOOL*)malloc(10 * sizeof(BOOL));
	memset(pbyFlag, 0, 10 * sizeof(BOOL));

	for (int i = 123; i <= 987;i++)
	{
		int j = nInputB * i / nInputA;
		int k = nInputC * j / nInputB;
		if (j > 987 || k > 987)
			continue;

		pbyFlag[i % 10] = 1; pbyFlag[i / 10 % 10] = 1; pbyFlag[i / 100] = 1;
		pbyFlag[j % 10] = 1; pbyFlag[j / 10 % 10] = 1; pbyFlag[j / 100] = 1;
		pbyFlag[k % 10] = 1; pbyFlag[k / 10 % 10] = 1; pbyFlag[k / 100] = 1;

		for (int l = 1; l < 10; l++)
		{
			if (!pbyFlag[l])
				bIsRight = false;
			pbyFlag[l] = 0;
		}

		if (bIsRight)
		{
			bIsPrint = true;
			printf("%d %d %d\n", i, j, k);
		}
		bIsRight = true;
	}

	if (!bIsPrint)
		printf("No!!!\n");

Exit0:

	return 0;
}