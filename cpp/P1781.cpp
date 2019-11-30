/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 14:49
//	Comment		:	OJ(P1781)
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
	pbyIsPrime[1] = true;
	return nIndex;
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nMaxLenght					= 0;
	string			szManNum					= "0";
	int				nMaxIndex					= 0;
	string*			pszInput					= NULL;

	scanf("%d", &nInputN);

	pszInput = new string[nInputN];

	for (int i = 0; i < nInputN; i++)
	{
		cin >> pszInput[i];
		if (pszInput[i].length() > nMaxLenght)
			nMaxLenght = pszInput[i].length();
	}
		

	for (int i = 0; i < nInputN; i++)
	{
		for (int j = pszInput[i].length(); j < nMaxLenght; j++)
			pszInput[i] = '0' + pszInput[i];
	}

	for (int i = 0; i < nInputN; i++)
	{
		if (pszInput[i] > szManNum)
		{
			szManNum = pszInput[i];
			nMaxIndex = i;
		}
	}
	printf("%d\n", nMaxIndex + 1);
	cout << szManNum << endl;;




Exit0:

	return 0;
}