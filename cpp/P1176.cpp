/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-11 18:59
//	Comment		:	OJ(1176)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;






int main(int argc, char* argv[])
{
	int							nInputN;
	int							nInputM;
	int							nX;
	int							nY;
	int**						ppnDP			= NULL;
	int**						mapFlag;


	scanf("%d%d", &nInputN, &nInputM);



	ppnDP = (int**)malloc((nInputN + 1) * sizeof(int*));
	mapFlag = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 0; i <= nInputN; i++)
	{
		ppnDP[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		mapFlag[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnDP[i], 0, (nInputN + 1) * sizeof(int));
		memset(mapFlag[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nX, &nY);
		mapFlag[nX][nY] = true;
	}

	ppnDP[1][1] = 1;


	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
		{
			if (mapFlag[i][j])
				ppnDP[i][j] = 0;
			else
			{
				ppnDP[i][j] += ppnDP[i - 1][j] + ppnDP[i][j - 1];
				ppnDP[i][j] %= 100003;
			}
				
		}


	printf("%d", ppnDP[nInputN][nInputN]);





Exit0:

	return 0;
}