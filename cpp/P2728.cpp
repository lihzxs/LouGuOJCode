/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-6 21:26
//	Comment		:	OJ(P2728)
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
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int*			pnFlag		= NULL;
	int				ppnDate[6][15];
	int				nCount		= 0;
	pnFlag = (int*)malloc(360 * sizeof(int));
	for (int i = 1; i <= 5; i++)
	{
		scanf("%d%d", &ppnDate[i][0], &ppnDate[i][1]);
		for (int j = 0; j < ppnDate[i][1]; j++)
		{
			scanf("%d%d", &ppnDate[i][2 + j * 2], &ppnDate[i][3 + j * 2]);
			ppnDate[i][3 + j * 2] += ppnDate[i][2 + j * 2];
		}
			

	}

	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			if (i == j)
				continue;
			if (ppnDate[i][0] == ppnDate[j][0])
			{
				int			nJudge = 1;
				memset(pnFlag, 0, 360 * sizeof(int));
				for (int k = 0; k < ppnDate[i][1]; k++)
				{
					for (int n = ppnDate[i][2 + k * 2]; n < ppnDate[i][3 + k * 2]; n++)
						pnFlag[n % 360] = 1;
				}

				for (int k = 0; k < ppnDate[j][1]; k++)
				{
					if (nJudge)
						for (int n = ppnDate[j][2 + k * 2]; n < ppnDate[j][3 + k * 2]; n++)
						{
							if (pnFlag[n % 360])
							{
								nJudge = 0;
								break;
							}
						}	
				}

				if (nJudge)
				{
					printf("none");
					return 0;
				}

			}///if (ppnDate[i][0] == ppnDate[j][0])
		}///for (int j = 1; j <= 5; j++)
	}

	while (true)
	{
		memset(pnFlag, 0, 360 * sizeof(int));
		for (int i = 1; i <= 5; i++)
		{
			for (int k = 0; k < ppnDate[i][1]; k++)
			{
				for (int n = ppnDate[i][2 + k * 2] + ppnDate[i][0] * nCount;
					n <= ppnDate[i][3 + k * 2] + ppnDate[i][0] * nCount; n++)
				{
					pnFlag[n % 360]++;
					if (pnFlag[n % 360] == 5)
					{
						printf("%d", nCount);
						return 0;
					}
				}
			}///for (int k = 0; k < ppnDate[i][1]; k++)

		}
		nCount++;
		if (nCount > 360)
		{
			printf("none");
			return 0;
		}
	}

Exit0:

	return 0;
}