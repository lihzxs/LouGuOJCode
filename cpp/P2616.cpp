/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 19:10
//	Comment		:	OJ(P2616)
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
	int				nInputE;
	int				nInputK;
	int				nInputX;
	int				nNum;
	int				nSpeed;
	int*			pnBagForm				= NULL;

	scanf("%d%d%d", &nInputK, &nInputE, &nInputN);

	pnBagForm = (int*)malloc((nInputK + 1) * sizeof(int));
	for (int i = 1; i < nInputK + 1; i++)
	{
		pnBagForm[i] = 40000000;
	}
	pnBagForm[0] = 0;
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d", &nInputX, &nNum, &nSpeed);
		nSpeed += nInputE - nInputX;
		for (int j = nInputK; j >= 0; j--)
		{
			for (int k = 0; k <= nNum; k++)
				if (j - k >= 0)
					pnBagForm[j] = min(pnBagForm[j - k] + k * nSpeed, 
						pnBagForm[j]);
		}
	}

	printf("%d", pnBagForm[nInputK]);





Exit0:

	return 0;
}