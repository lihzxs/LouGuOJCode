/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 16:03
//	Comment		:	OJ(P2356)
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
#define	EPS         1e-8

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
	int					nInputN;
	int					nGetPoint		= 0;
	int					nAns			= 0;
	int					nFlag			= 0;
	scanf("%d", &nInputN);

	

	for (int i = 0; i < nInputN; i++)
		for (int j = 0; j < nInputN; j++)
			scanf("%d", &g_nMat[i][j]);

	for (int i = 0; i < nInputN; i++)
		for (int j = 0; j < nInputN; j++)
		{
			if (g_nMat[i][j] == 0)
			{
				nFlag = 1;
				for (int k = 0; k < nInputN; k++)
				{
					if (g_nMat[i][k] > 0)
						nGetPoint += g_nMat[i][k];
				}
				for (int k = 0; k < nInputN; k++)
				{
					if (g_nMat[k][j] > 0)
						nGetPoint += g_nMat[k][j];
				}
				if (nGetPoint > nAns)
					nAns = nGetPoint;
				nGetPoint = 0;
			}
		}///for (int j = 0; j < nInputN; j++)

    if (nFlag)
		printf("%d", nAns);
	else
		printf("Bad Game!");

Exit0:

	return 0;
}




