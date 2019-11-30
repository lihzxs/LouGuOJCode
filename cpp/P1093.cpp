/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-20 20:42
//	Comment		:	OJ(P1093)
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
#define	MAXNUM		7010
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

typedef struct SScore
{
	int			nChinese;
	int			nId;
	int			nSum;
}SScore;


bool cmp(const SScore sFirst, const SScore sSecond)
{
	if (sFirst.nSum == sSecond.nSum)
	{
		if (sFirst.nChinese == sSecond.nChinese)
			return sFirst.nId < sSecond.nId;
		return sFirst.nChinese > sSecond.nChinese;
	}
	return sFirst.nSum > sSecond.nSum;
}

int main(int argc, char* argv[])
{
	
	int			nInputN;
	int			nEnglish;
	int			nMath;
	SScore*		sScore;

	scanf("%d", &nInputN);

	sScore = (SScore*)malloc(nInputN * sizeof(SScore));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d", &sScore[i].nChinese, &nMath, &nEnglish);
		sScore[i].nSum = sScore[i].nChinese + nMath + nEnglish;
		sScore[i].nId = i + 1;
	}

	sort(sScore, sScore + nInputN, cmp);

	for (int i = 0; i < 5; i++)
		printf("%d %d\n", sScore[i].nId, sScore[i].nSum);

Exit0:

	return 0;
}