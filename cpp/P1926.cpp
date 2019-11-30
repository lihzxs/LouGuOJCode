/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-1 20:46
//	Comment		:	OJ(P1926)
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
	int				nInputK;
	int				nInputR;
	int				nCount					= 0;
	int*			pnBagForm				= NULL;
	int*			pnLike					= NULL;
	int*			pnScore					= NULL;
	int*			pnTime					= NULL;
	int				nRecord					= 0;
	scanf("%d%d%d%d", &nInputN, &nInputM, &nInputK, &nInputR);


	pnBagForm = (int*)malloc((nInputR + 1) * sizeof(int));
	pnScore = (int*)malloc(nInputM * sizeof(int));
	pnTime = (int*)malloc(nInputM * sizeof(int));
	pnLike = (int*)malloc(nInputN * sizeof(int));
	memset(pnBagForm, 0, (nInputR + 1) * sizeof(int));
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnLike + i);
	sort(pnLike, pnLike + nInputN);

	for (int i = 0; i < nInputM; i++)
		scanf("%d", pnTime + i);

	for (int i = 0; i < nInputM; i++)
		scanf("%d", pnScore + i);


	for (int i = 0; i < nInputM; i++)
	{
		for (int j = nInputR; j >= pnTime[i]; j--)
			pnBagForm[j] = max(pnBagForm[j],
				pnBagForm[j - pnTime[i]] + pnScore[i]);
	}


	for (nRecord = 0; nRecord <= nInputR; nRecord++)
	{
		if (pnBagForm[nRecord] == nInputK)
			break;
	}



	nInputR -= nRecord;


	for (int i = 0; i < nInputN; i++)
		if (nInputR >= pnLike[i])
		{
			nCount++;
			nInputR -= pnLike[i];
		}
		else
			break;


	printf("%d\n", nCount);



Exit0:

	return 0;
}