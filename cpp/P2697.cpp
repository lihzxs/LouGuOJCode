/////
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-21 21:05
//	Comment		:	OJ(P2697)
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	string		szInput;
	int			nAns			 = 0;
	int*		pnLocal			 = NULL;
	int*		pnSum			 = NULL;

	cin >> szInput;

	pnLocal = (int*)malloc((szInput.length() + 1) * sizeof(int));
	pnSum = (int*)malloc((szInput.length() + 1) * sizeof(int));
	memset(pnLocal, 0, (szInput.length() + 1) * sizeof(int));
	memset(pnSum, 0, (szInput.length() + 1) * sizeof(int));


	for (int i = 1; i <= szInput.length(); i++)
	{
		if (szInput[i - 1] == 'G')
			pnSum[i] = pnSum[i - 1] + 1;
		else
			pnSum[i] = pnSum[i - 1] - 1;
	}
		

	for (int i = 1; i <= szInput.length(); i++)
	{
		if (pnLocal[pnSum[i]] != 0 || pnSum[i] == 0)
			nAns = max(i - pnLocal[pnSum[i]], nAns);
		else
			pnLocal[pnSum[i]] = i;
	}

	printf("%d", nAns);


Exit0:

	return 0;
}