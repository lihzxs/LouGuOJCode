/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 20:21
//	Comment		:	OJ(P1838)
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
#define	MAXNUM		5
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


int			g_nMat[MAXNUM][MAXNUM];
int main(int argc, char* argv[])
{
	string			szInput;
	int				nFlag		= 1;
	int				nTemp		= 0;

	for (int i = 0; i < MAXNUM; i++)
		for (int j = 0; j < MAXNUM; j++)
			g_nMat[i][j] = 0;

	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
	{
		g_nMat[(szInput[i] - '0' - 1) / 3 + 1][(szInput[i] - '0' - 1) % 3 + 1] = nFlag;
		nFlag = -nFlag;
	}

	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
		{
			if (g_nMat[i][j] == g_nMat[i - 1][j] &&
				g_nMat[i][j] == g_nMat[i + 1][j])
				nTemp = g_nMat[i][j];
			if (nTemp == 1)
			{
				printf("xiaoa wins.\n");
				return 0;
			}
			else if (nTemp == -1)
			{
				printf("uim wins.\n");
				return 0;
			}

			if (g_nMat[i][j] == g_nMat[i][j - 1] &&
				g_nMat[i][j] == g_nMat[i][j + 1])
				nTemp = g_nMat[i][j];
			if (nTemp == 1)
			{
				printf("xiaoa wins.\n");
				return 0;
			}
			else if (nTemp == -1)
			{
				printf("uim wins.\n");
				return 0;
			}

			if (g_nMat[i][j] == g_nMat[i - 1][j - 1] &&
				g_nMat[i][j] == g_nMat[i + 1][j + 1])
				nTemp = g_nMat[i][j];
			if (nTemp == 1)
			{
				printf("xiaoa wins.\n");
				return 0;
			}
			else if (nTemp == -1)
			{
				printf("uim wins.\n");
				return 0;
			}

			if (g_nMat[i][j] == g_nMat[i + 1][j - 1] &&
				g_nMat[i][j] == g_nMat[i - 1][j + 1])
				nTemp = g_nMat[i][j];
			if (nTemp == 1)
			{
				printf("xiaoa wins.\n");
				return 0;
			}
			else if (nTemp == -1)
			{
				printf("uim wins.\n");
				return 0;
			}
				




		}//for (int j = 4; j < 7; j++)

	printf("drew.\n");




Exit0:

	return 0;
}







