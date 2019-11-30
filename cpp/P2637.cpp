/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 21:04
//	Comment		:	OJ(P2637)
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
	int				nInputN;
	int				nInputM;
	int*			pnInputPrice;
	int				nPrice;
	int				nAns			= 0;
	int				nGetMoney		= 0;
	scanf("%d%d", &nInputN, &nInputM);

	pnInputPrice = (int*)malloc(nInputM * sizeof(int));

	for (int i = 0; i < nInputM; i++)
		scanf("%d", pnInputPrice + i);

	sort(pnInputPrice, pnInputPrice + nInputM);

	for (int i = nInputM - 1; i >= 0; i--)
	{
		nGetMoney += pnInputPrice[i] * (nInputM - i);
		if (nAns < nGetMoney)
		{
			nAns = nGetMoney;
			nPrice = pnInputPrice[i];
		}
		nGetMoney = 0;
	}

	printf("%d %d", nPrice, nAns);

	


Exit0:

	return 0;
}




