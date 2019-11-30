/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-20 22:14
//	Comment		:	OJ(P2639)
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
#define	MAXNUM		7010
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputH;
	int				nInputN;
	int				nAns						= 0;
	int				nInputTemp;
	int*			pnInputSeq					= NULL;
	int*			pnBagFrom					= NULL;
	scanf("%d%d", &nInputH, &nInputN);

	pnInputSeq = (int*)malloc(nInputN * sizeof(int));
	pnBagFrom = (int*)malloc((nInputH + 1) * sizeof(int));
	memset(pnBagFrom, 0, (nInputH + 1) * sizeof(int));


	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		for (int j = nInputH; j >= 0; j--)
		{
			if (j >= nInputTemp)
				pnBagFrom[j] = max(pnBagFrom[j],
					pnBagFrom[j - nInputTemp] + nInputTemp);
		}
	}

	printf("%d", pnBagFrom[nInputH]);





	


Exit0:

	return 0;
}