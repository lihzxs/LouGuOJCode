/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-19 22:43
//	Comment		:	OJ(P1794)
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
	int				nInputV;
	int				nInputG;
	int				nInputN;
	int**			ppnBagForm			 = NULL;
	int				nFire;
	int				nV;
	int				nG;
	scanf("%d%d", &nInputV, &nInputG);
	scanf("%d", &nInputN);

	ppnBagForm = (int**)malloc((nInputV + 1) * sizeof(int*));

	for (int i = 0; i <= nInputV; i++)
	{
		ppnBagForm[i] = (int*)malloc((nInputG + 1) * sizeof(int));
		memset(ppnBagForm[i], 0, (nInputG + 1) * sizeof(int));
	}

	for (int z = 0; z < nInputN; z++)
	{
		scanf("%d%d%d", &nFire, &nV, &nG);
		for (int i = nInputV; i >= nV; i--)
			for (int j = nInputG; j >= nG; j--)
				ppnBagForm[i][j] = max(ppnBagForm[i][j],
					ppnBagForm[i - nV][j - nG] + nFire);
	}

	printf("%d", ppnBagForm[nInputV][nInputG]);



Exit0:
	return 0;
}