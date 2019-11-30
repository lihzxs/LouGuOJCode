/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 13:20
//	Comment		:	OJ(P1598)
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


bool IsLeapYear(int nYear)
{
	return ((nYear % 400) == 0 || (nYear % 100 != 0 && nYear % 4 == 0));
}


int main(int argc, char* argv[])
{

	int*				pnCount				= NULL;
	int**				ppnOutput			= NULL;
	int					nMax				= 0;
	string				szInput;

	pnCount = (int*)malloc(26 * sizeof(int));
	memset(pnCount, 0, 26 * sizeof(int));

	getline(cin, szInput);

	for (int i = 0; i < szInput.length(); i++)
		if (szInput[i] >= 'A' && szInput[i] <= 'Z')
			pnCount[szInput[i] - 'A']++;

	getline(cin, szInput);

	for (int i = 0; i < szInput.length(); i++)
		if (szInput[i] >= 'A' && szInput[i] <= 'Z')
			pnCount[szInput[i] - 'A']++;
	getline(cin, szInput);

	for (int i = 0; i < szInput.length(); i++)
		if (szInput[i] >= 'A' && szInput[i] <= 'Z')
			pnCount[szInput[i] - 'A']++;

	getline(cin, szInput);

	for (int i = 0; i < szInput.length(); i++)
		if (szInput[i] >= 'A' && szInput[i] <= 'Z')
			pnCount[szInput[i] - 'A']++;

	for (int i = 0; i < 26; i++)
		if (pnCount[i] > nMax)
			nMax = pnCount[i];


	ppnOutput = (int**)malloc(nMax * sizeof(int*));
	for (int i = 0; i < nMax; i++)
	{
		ppnOutput[i] = (int*)malloc(26 * sizeof(int));
		memset(ppnOutput[i], 0, 26 * sizeof(int));
	}



	for (int i = 0; i < 26; i++)
	{
		for (int j = nMax - 1; j >= nMax - pnCount[i]; j--)
		{
			ppnOutput[j][i] = 1;
		}
	}



	for (int i = 0; i < nMax; i++)
	{
		if (ppnOutput[i][0])
			printf("*");
		else
			printf(" ");
		for (int j = 1; j < 26; j++)
			if (ppnOutput[i][j])
				printf(" *");
			else
				printf("  ");

		printf("\n");
	}

	printf("A");
	for (int i = 1; i < 26; i++)
		printf(" %c", 'A' + i);

	printf("\n");




















	


Exit0:

	return 0;
}