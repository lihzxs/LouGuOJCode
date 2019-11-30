/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-4 18:21
//	Comment		:	OJ(P2556)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;





int main(int argc, char* argv[])
{
	int					nInputN;
	int*				pnSeq				= NULL;
	int					nTemp;
	string				szImg				= "";	
	string				szTemp;
	int					nCount				= 0;
	int					nPreIndex			= 0;
	int					nPre				= 0;
	pnSeq = (int*)malloc(8 * sizeof(int));
	memset(pnSeq, 0, 8 * sizeof(int));

	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN / 8; i++)
	{
		scanf("%d", &nTemp);
		while (nTemp)
		{
			pnSeq[nCount++] = nTemp % 2;
			nTemp /= 2;
		}
		for (int i = 7; i >= 0; i--)
			szImg += to_string(pnSeq[i]);

		nCount = 0;
		memset(pnSeq, 0, 8 * sizeof(int));
	}
	szImg += to_string(!(szImg[szImg.length() - 1] - '0'));
	nPre = szImg[0] - '0';
	for (int i = 0; i < szImg.length(); i++)
	{
		if (szImg[i] - '0' != nPre)
		{
			if (nPre == 1)
				printf("%d ", 128 + i - nPreIndex);
			else
				printf("%d ", i - nPreIndex);
			nPreIndex = i;
			nPre = szImg[i] - '0';
		}
	}


Exit0:
	return 0;
}