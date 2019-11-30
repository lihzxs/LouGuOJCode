/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 18:37
//	Comment		:	OJ(P2705)
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
#define	MAXNUM		7
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




int main(int argc, char* argv[])
{
	int			nR;
	int			nB;
	int			nC;
	int			nD;
	int			nE;
	int			nAns			= 0;

	scanf("%d%d%d%d%d", &nR, &nB, &nC, &nD, &nE);

	nAns = nR * nC + nB * nD;
	nAns = max(nAns, min(nR, nB) * nE * 2 + (nR > nB ? (nR - nB) * nC : (nB - nR) * nD));

	printf("%d\n", nAns);





Exit0:

	return 0;
}







