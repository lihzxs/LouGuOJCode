/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 15:00
//	Comment		:	OJ(P3717)
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
#define	MAXNUM		150
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


int				g_nMat[MAXNUM][MAXNUM];
int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int			nInputR;
	int			nInputX;
	int			nInputY;
	int			nAns			= 0;
	scanf("%d%d%d", &nInputN, &nInputM, &nInputR);

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
			g_nMat[j][i] = 0;

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nInputX, &nInputY);
		for (int i = nInputX - nInputR; i <= nInputX + nInputR; i++)
			for (int j = nInputY - nInputR; j <= nInputY + nInputR; j++)
			{
				if (i <= 0 || j <= 0 || i > nInputN || j > nInputN)
					continue;
				if ((i - nInputX) * (i - nInputX) + (j - nInputY) * (j - nInputY) <=
					nInputR * nInputR && g_nMat[j][i] == 0)
				{
					g_nMat[j][i] = 1;
					nAns++;
				}
			}
	}

	printf("%d", nAns);
	













Exit0:

	return 0;
}




