/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 20:43
//	Comment		:	OJ(P5082)
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
#include <vector>
#include <map>
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


int main(int argc, char* argv[])
{
	int			nInputN				= 0;
	int			nMaxScoreSum		= 0;
	int			nGetScoreSum		= 0;
	int			nInputTemp;
	double		fAns;

	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		nMaxScoreSum += nInputTemp;
	}
		
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		nGetScoreSum += nInputTemp;
	}

	fAns = (nMaxScoreSum * 3.0 - nGetScoreSum * 2.0) /
		(nMaxScoreSum - nGetScoreSum);

	printf("%.6f", fAns);





	


Exit0:

	return 0;
}




