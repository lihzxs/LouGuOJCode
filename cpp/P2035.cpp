/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 19:53
//	Comment		:	OJ(P2035)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

typedef struct SSong
{
	int		nId;
	int		nQ;
}SSong;

bool Cmp(const SSong sFirst, const SSong sSecond)
{
	if (sFirst.nQ == sSecond.nQ)
		return sFirst.nId < sSecond.nId;
	return sFirst.nQ > sSecond.nQ;
}
bool CmpById(const SSong sFirst, const SSong sSecond)
{
	return sFirst.nId < sSecond.nId;
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputT;
	SSong*			psSong			= NULL;
	int				nMod			= 0;
	int				nDiv;
	int				nTempId;

	scanf("%d%d", &nInputN, &nInputT);

	psSong = (SSong*)malloc(nInputN * sizeof(SSong));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &psSong[i].nQ);
		psSong[i].nId = i + 1;
	}

	

	while (nInputT != 0)
	{
		sort(psSong, psSong + nInputN, Cmp);
		printf("%d\n", psSong[0].nId);
		nDiv = psSong[0].nQ / (nInputN - 1);
		nMod = psSong[0].nQ % (nInputN - 1);
		psSong[0].nQ = 0;
		for (int i = 1; i < nInputN; i++)
			psSong[i].nQ += nDiv;

		if (nMod > 0)
		{
			nTempId = psSong[0].nId;
			sort(psSong, psSong + nInputN, CmpById);
			for (int i = 0; i < nInputN && nMod > 0; i++)
				if (psSong[i].nId != nTempId)
				{
					psSong[i].nQ++;
					nMod--;
				}
		}
		nInputT--;
	}





Exit0:

	return 0;
}