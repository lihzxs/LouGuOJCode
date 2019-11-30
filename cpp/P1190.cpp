/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-24 20:21
//	Comment		:	OJ(P1190)
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
#define	MAXNUM		1000000001
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputTemp;
	int*			pnWater			= NULL;
	BOOL			bFlag			= true;
	int				nAns			= 0;

	scanf("%d%d", &nInputN, &nInputM);

	if (nInputN <= nInputM || nInputM == 1)
	{
		for (int i = 0; i < nInputN; i++)
		{
			scanf("%d", &nInputM);
			nAns += nInputM;
		}
		printf("%d", nAns);
		return 0;
	}

	pnWater = (int*)malloc(nInputM * sizeof(int));

	for (int i = 0; i < nInputM; i++)
		scanf("%d", pnWater + i);
	nInputN -= nInputM;
	while (bFlag)
	{
		bFlag = false;
		nAns++;
		for (int i = 0; i < nInputM; i++)
		{
			if (pnWater[i] == 0)
			{
				nInputTemp = 0;
				if (nInputN != 0)
				{
					scanf("%d", &nInputTemp);
					nInputN--;
				}
				pnWater[i] = nInputTemp;
			}
			if (pnWater[i])
				pnWater[i]--;
		}
		for (int i = 0; i < nInputM; i++)
			if (pnWater[i])
			{
				bFlag = true;
				break;
			}

	}

	printf("%d", nAns);






			

Exit0:

	return 0;
}