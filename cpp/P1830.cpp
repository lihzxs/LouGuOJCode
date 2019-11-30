/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 19:34
//	Comment		:	OJ(P1830)
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
#define	MAXNUM		101
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



int			g_nMat[MAXNUM][MAXNUM][2];
int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int			nInputX;
	int			nInputY;
	int			nTempX1;
	int			nTempY1;
	int			nTempX2;
	int			nTempY2;


	scanf("%d%d%d%d", &nInputN, &nInputM, &nInputX, &nInputY);

	//for (int i = 0; i < nInputN; i++)
	//	for (int j = 0; j < nInputM; j++)
	//		g_nMat[i][j][0] = g_nMat[i][j][1] = 0;


	for (int i = 0; i < nInputX; i++)
	{
		scanf("%d%d%d%d", &nTempX1, &nTempY1, &nTempX2, &nTempY2);
		for (int j = nTempX1; j <= nTempX2; j++)
			for (int k = nTempY1; k <= nTempY2; k++)
			{
				g_nMat[j][k][0]++;
				g_nMat[j][k][1] = i + 1;
			}
	}

	for (int i = 0; i < nInputY; i++)
	{
		scanf("%d%d", &nTempX1, &nTempY1);
		if (g_nMat[nTempX1][nTempY1][0])
			printf("Y %d %d\n", g_nMat[nTempX1][nTempY1][0],
				g_nMat[nTempX1][nTempY1][1]);
		else
			printf("N\n");

	}


Exit0:

	return 0;
}







