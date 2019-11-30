/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 14:22
//	Comment		:	OJ(P1125)
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


int PrimeInit(unsigned int* punSeq, BYTE* pbyIsPrime)
{
	int		nIndex = 0;
	memset(pbyIsPrime, true, MAXNUM * sizeof(BYTE));
	for (int i = 2; i < MAXNUM; i++)
	{
		if (pbyIsPrime[i])
		{
			punSeq[nIndex++] = i;
			for (int j = i * 2; j < MAXNUM; j += i)
				pbyIsPrime[j] = 0;
		}
	}
	pbyIsPrime[0] = false;
	pbyIsPrime[1] = false;
	return nIndex;
}


int main(int argc, char* argv[])
{
	BYTE*				pbyIsPrime		= NULL;
	unsigned int*		punSeq			= NULL;
	int					nIndex			= 0;
	int*				pnCount			= NULL;
	int					nMax			= 0;
	int					nMin			= 150;
	string				szInput;

	pnCount = (int*)malloc(26 * sizeof(int));
	memset(pnCount, 0, 26 * sizeof(int));

	pbyIsPrime = (BYTE*)malloc(MAXNUM * sizeof(BYTE));

	punSeq = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));


	nIndex = PrimeInit(punSeq, pbyIsPrime);

	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
		pnCount[szInput[i] - 'a']++;

	for (int i = 0; i < 26; i++)
	{
		if (pnCount[i] > nMax)
			nMax = pnCount[i];
		if (pnCount[i] < nMin && pnCount[i] != 0)
			nMin = pnCount[i];
	}
	
	if (pbyIsPrime[nMax - nMin])
	{
		printf("Lucky Word\n");
		printf("%d\n", nMax - nMin);
	}
	else
		printf("No Answer\n0\n");
		





Exit0:

	return 0;
}