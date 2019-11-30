/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-25 20:59
//	Comment		:	OJ(P2615)
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
	int					nPreX;
	int					nPreY;
	int**				ppnMat					= NULL;
	int					nK						= 1;
	scanf("%d", &nInputN);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	nPreX = nInputN / 2 + 1;
	nPreY = 1;
	ppnMat[nPreY][nPreX] = nK;
	nK++;

	while (nK <= nInputN * nInputN)
	{
		if (nPreY == 1 && nPreX != nInputN)
		{
			nPreX = nPreX + 1;
			nPreY = nInputN;
		}
		else if (nPreX == nInputN && nPreY != 1)
		{
			nPreX = 1;
			nPreY = nPreY - 1;
		}
		else if (nPreY == 1 && nPreX == nInputN)
		{
			nPreX = nInputN;
			nPreY = nPreY + 1;
		}
		else
		{
			if (ppnMat[nPreY - 1][nPreX + 1] == 0)
			{
				nPreX = nPreX + 1;
				nPreY = nPreY - 1;
			}
			else
			{
				nPreY = nPreY + 1;
			}
		}

		ppnMat[nPreY][nPreX] = nK;
		nK++;


	}

	for (int i = 1; i < nInputN + 1; i++)
	{
		printf("%d", ppnMat[i][1]);
		for (int j = 2; j < nInputN + 1; j++)
		{
			printf(" %d", ppnMat[i][j]);
		}
		printf("\n");
	}



		




		


Exit0:

	return 0;
}