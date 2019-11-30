/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-31 22:13
//	Comment		:	OJ(P1076)
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
	int				nInputN;
	int				nInputM;
	int				nSum				= 0;
	int				nStart;
	int**			ppnMat				= NULL;
	int**			ppnFlag				= NULL;
	int*			pnCountDoor			= NULL;
	int				nCount				= 0;
	int				nTemp;
	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppnFlag = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc(nInputM * sizeof(int));
		ppnFlag[i] = (int*)malloc(nInputM * sizeof(int));
	}
		
	pnCountDoor = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnCountDoor, 0, (nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
		for (int j = 0; j < nInputM; j++)
		{
			scanf("%d %d", &ppnFlag[i][j], &ppnMat[i][j]);
			pnCountDoor[i] += ppnFlag[i][j];
		}
			

	scanf("%d", &nStart);

	for (int i = 1; i <= nInputN; i++)
	{
		nSum += ppnMat[i][nStart];
		nSum %= 20123;
		nCount = 0;
		ppnMat[i][nStart] = (ppnMat[i][nStart] - 1) % pnCountDoor[i];
		ppnMat[i][nStart]++;
		nTemp = nStart;
		while (nCount < ppnMat[i][nStart])
		{
			nCount += ppnFlag[i][nTemp];
			if (nCount == ppnMat[i][nStart])
				break;
			nTemp++;
			if (nTemp == nInputM)
				nTemp = 0;
		}
		nStart = nTemp;
	}
	printf("%d", nSum);
Exit0:
	return 0;
}