/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-8 16:26
//	Comment		:	OJ(P1205)
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


void TrueRight(int** ppnMat, int** ppnAns, int nNum) 
{
	for (int i = 1; i <= nNum; i++)
		for (int j = 1; j <= nNum; j++)
			ppnAns[j][nNum - i + 1] = ppnMat[i][j];
	for (int i = 1; i <= nNum; i++)
		for (int j = 1; j <= nNum; j++)
			ppnMat[i][j] = ppnAns[i][j];
}


void TrueFlex(int** ppnMat, int** ppnAns, int nNum)
{
	for (int i = 1; i <= nNum; i++)
		for (int j = 1; j <= nNum; j++)
			ppnAns[i][nNum - j + 1] = ppnMat[i][j];

	for (int i = 1; i <= nNum; i++)
		for (int j = 1; j <= nNum; j++)
			ppnMat[i][j] = ppnAns[i][j];
}


bool IsEqual(int** ppnMat, int** ppnAns, int nNum)
{
	for (int i = 1; i <= nNum; i++)
		for (int j = 1; j <= nNum; j++)
			if (ppnAns[i][j] != ppnMat[i][j])
				return false;

	return true;
}


int main(int argc, char* argv[])
{
	int				nInputN;
	string			szInput;
	int**			ppnMat				= NULL;
	int**			ppnMatTemp			= NULL;
	int**			ppnAnsMat			= NULL;

	scanf("%d", &nInputN);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppnMatTemp = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppnAnsMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		ppnMatTemp[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		ppnAnsMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
			if (szInput[j] == '@')
				ppnMat[i][j + 1] = 1;
			else
				ppnMat[i][j + 1] = 0;
	}
	
	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
			if (szInput[j] == '@')
				ppnAnsMat[i][j + 1] = 1;
			else
				ppnAnsMat[i][j + 1] = 0;
	}



	for (int i = 1; i <= 4; i++)
	{
		TrueRight(ppnMat, ppnMatTemp, nInputN);
		if (IsEqual(ppnMat, ppnAnsMat, nInputN))
		{
			if (i == 4)
				printf("6\n");
			else
				printf("%d\n", i);
			return 0;
		}
	}

	TrueFlex(ppnMat, ppnMatTemp, nInputN);
	if (IsEqual(ppnMat, ppnAnsMat, nInputN))
	{
		printf("4\n");
		return 0;
	}
	for (int i = 1; i < 3; i++)
	{
		TrueRight(ppnMat, ppnMatTemp, nInputN);
		if (IsEqual(ppnMat, ppnAnsMat, nInputN))
		{
			printf("5\n");
			return 0;
		}
	}
	printf("7\n");












Exit0:

	return 0;
}