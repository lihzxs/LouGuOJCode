/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 13:57
//	Comment		:	OJ(P1789)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		2000
#define	EPS         0.0001

#define ERROR_ID    0

#define PROCESS_ERROR(Condition)    \
{                                   \
        if (!(Condition))           \
        {                           \
            goto Exit0;             \
        }                           \
}


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int         g_nMat[MAXNUM][MAXNUM];
int main(int argc, char* argv[])
{
	int         nInputN;
	int         nInputM;
	int         nInputK;
	int         nInputX;
	int         nInputY;
	int         nAns = 0;
	scanf("%d%d%d", &nInputN, &nInputM, &nInputK);

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
			g_nMat[i][j] = 0;


	for (int i = 1; i <= nInputM; i++)
	{
		scanf("%d%d", &nInputX, &nInputY);
		for (int j = nInputX - 2; j <= nInputX + 2; j++)
		{
			if (j <= 0)
				continue;
			g_nMat[nInputY][j] = 1;
		}
		for (int j = nInputY - 2; j <= nInputY + 2; j++)
		{
			if (j <= 0)
				continue;
			g_nMat[j][nInputX] = 1;
		}
		for (int j = nInputX - 1; j <= nInputX + 1; j++)
			for (int k = nInputY - 1; k <= nInputY + 1; k++)
			{
				if (j <= 0 || k <= 0)
					continue;
				g_nMat[k][j] = 1;
			}
	}

	for (int i = 1; i <= nInputK; i++)
	{
		scanf("%d%d", &nInputX, &nInputY);
		for (int j = nInputX - 2; j <= nInputX + 2; j++)
			for (int k = nInputY - 2; k <= nInputY + 2; k++)
			{
				if (j <= 0 || k <= 0)
					continue;
				g_nMat[j][k] = 1;
			}
	}


	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
			if (g_nMat[i][j] == 0)
				nAns++;

	printf("%d", nAns);










Exit0:

	return 0;
}




