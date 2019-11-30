/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-28 17:38
//	Comment		:	OJ(P1808)
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


bool Cmp(int* pnOne, int* pnTwo)
{
	for (int i = 0; i < 26; i++)
		if (pnOne[i] != pnTwo[i])
			return false;
	return true;
}





int main(int argc, char* argv[])
{
	int*			pnWordFlag			= NULL;
	string			szInput;
	int				nAns				= 0;
	int				nInputN;
	string*			szAns				= NULL;
	
	
	cin >> nInputN;

	pnWordFlag = (int*)malloc(26 * sizeof(int));
	memset(pnWordFlag, 0, 26 * sizeof(int));
	szAns = new string[nInputN];

	for (int i = 0; i < nInputN; i++)
	{
		szAns[i] = "";
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
			pnWordFlag[szInput[j] - 'A']++;
		for (int j = 0; j < 26; j++)
			if (pnWordFlag[j] > 0)
				szAns[i] += to_string(pnWordFlag[j]) + to_string(j);

		memset(pnWordFlag, 0, 26 * sizeof(int));
	}

	sort(szAns, szAns + nInputN);

	for (int i = 0; i < nInputN - 1; i++)
	{
		if (szAns[i] != szAns[i + 1])
			nAns++;
	}
	printf("%d", ++nAns);





Exit0:

	return 0;
}