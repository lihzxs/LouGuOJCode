/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-25 17:04
//	Comment		:	OJ(P4470)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;






int main(int argc, char* argv[])
{
	int					nInputN;
	int					nCount;
	string*				pszSeq;
	string				szInput;
	BOOL*				pbFlag			= NULL;
	BOOL*				pbIsTrue		= NULL;
	scanf("%d", &nInputN);

	pbFlag = (BOOL*)malloc(26 * sizeof(BOOL));
	memset(pbFlag, false, 26 * sizeof(BOOL));

	pbIsTrue = (BOOL*)malloc(nInputN * sizeof(BOOL));
	memset(pbIsTrue, true, nInputN * sizeof(BOOL));

	pszSeq = new string[nInputN];

	for (int i = 0; i < nInputN; i++)
		cin >> pszSeq[i];

	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
	{
		for (int j = 0; j < nInputN; j++)
		{
			if (pszSeq[j][i] != szInput[i] || 
				pszSeq[i].length() < szInput.length())
				pbIsTrue[j] = false;
		}
	}
	for (int i = 0; i < nInputN; i++)
	{
		if (pbIsTrue[i])
			pbFlag[pszSeq[i][szInput.length()] - 'A'] = true;
	}

	printf("***");
	nCount = 3;
	for (int i = 0; i < 26; i++)
	{
		if (pbFlag[i])
			printf("%c", i + 'A');
		else
			printf("*");
		nCount++;
		if (nCount % 8 == 0)
			printf("\n");
	}
	printf("***");
		


Exit0:

	return 0;
}