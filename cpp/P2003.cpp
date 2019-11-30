/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-15 21:49
//	Comment		:	OJ(P2003)
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

typedef struct SDate
{
	int		nX1;
	int		nX2;
	int		nY;
}SDate;

bool Cmp(const SDate& sFirst, const SDate& sSecond)
{
	return sFirst.nY < sSecond.nY;
}
int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnFlag			= NULL;
	SDate*			psDate			= NULL;
	int				nSum			= 0;
	scanf("%d", &nInputN);

	pnFlag = (int*)malloc(200050 * sizeof(int));
	memset(pnFlag, 0, 200050 * sizeof(int));
	psDate = (SDate*)malloc(200 * sizeof(psDate));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d", &psDate[i].nY, &psDate[i].nX1, &psDate[i].nX2);
		psDate[i].nX1 *= 2;
		psDate[i].nX2 *= 2;
	}
	sort(psDate, psDate + nInputN, Cmp);

	for (int i = 0; i < nInputN; i++)
	{
		nSum += psDate[i].nY - pnFlag[psDate[i].nX1 + 1];
		nSum += psDate[i].nY - pnFlag[psDate[i].nX2 - 1];

		for (int j = psDate[i].nX1; j <= psDate[i].nX2; j++)
			pnFlag[j] = psDate[i].nY;
	}

	printf("%d", nSum);





Exit0:

	return 0;
}