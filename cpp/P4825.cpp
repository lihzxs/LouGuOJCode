/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-25 00:21
//	Comment		:	OJ(P4825)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <list>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		1000000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputX;
	int**			ppnMat				= NULL;
	int**			ppnAns				= NULL;

	scanf("%d%d%d", &nInputN, &nInputM, &nInputX);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppnAns = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		ppnAns[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnAns[i], 0, (nInputM + 1) * sizeof(int));
	}
		

	ppnAns[1][1] = 1;

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			scanf("%d", &ppnMat[i][j]);
			for (int k = 1; k < i; k++)
				for (int l = 1; l < j; l++)
				{
					if (ppnMat[k][l] != ppnMat[i][j])
						ppnAns[i][j] = (ppnAns[i][j] + ppnAns[k][l]) % MODNUM;
				}
		}

	printf("%d", ppnAns[nInputN][nInputM]);



Exit0:

	return 0;
}