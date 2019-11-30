/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 23:31
//	Comment		:	OJ(P2417)
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
	int					nT;
	int					nP;
	int					nN;
	int					nTemp;
	int					nNum;
	int					nSum = 0;
	int*				pnCount				= NULL;
	pnCount = (int*)malloc(20005 *sizeof(int));
	scanf("%d", &nT);

	while (nT--)
	{
		memset(pnCount, 0, 20005 * sizeof(int));
		scanf("%d%d", &nP, &nN);
		nSum = 0;
		for (int j = 1; j <= nP; j++)
		{
			scanf("%d", &nTemp);
			for (int i = 1; i <= nTemp; i++)
			{
				scanf("%d", &nNum);
				pnCount[nNum]++;
			}
		}

		for (int i = 1; i <= nN; i++)
		{
			if (pnCount[i] != 0)
				nSum++;
		}

		if (nSum < nP)
			printf("NO\n");
		else
			printf("YES\n");
	}

Exit0:
	return 0;
}