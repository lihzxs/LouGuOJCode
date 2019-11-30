/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 23:47
//	Comment		:	OJ(P1960)
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
	int					nStartH;
	int					nStartM;
	int					nEndH;
	int					nEndM;
	int					nTime;
	int					nInputM;
	int*				pnBag;
	int					nT;
	int					nC;
	int					nP;
	scanf("%d:%d%d:%d", &nStartH, &nStartM, &nEndH, &nEndM);
	nTime = (nEndH - nStartH) * 60 - nStartM + nEndM;

	pnBag = (int*)malloc((nTime + 1) * sizeof(int));
	memset(pnBag, 0, (nTime + 1) * sizeof(int));
	scanf("%d", &nInputM);
	for(int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nT, &nC, &nP);
		if (nP == 0)
		{
			for(int j = nT; j <= nTime; j++)
				pnBag[j] = max(pnBag[j], pnBag[j - nT] + nC);
		}
		else
		{
			for (int j = nTime; j >= 0; j--)
			{
				for (int k = 1; k <= nP; k++)
				{
					if (j - k * nT < 0)
						break;
					pnBag[j] = max(pnBag[j], pnBag[j - k * nT] + nC * k);
				}
			}
		}
	}

	printf("%d", pnBag[nTime]);




Exit0:
	return 0;
}