/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 11:03
//	Comment		:	OJ(P1421)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

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
	int			nYuan;
	int			nMao;
	int			nAns;
	double		fMoney;

	scanf("%d%d", &nYuan, &nMao);

	fMoney = nYuan + nMao / 10.0;
	nAns = fMoney / 1.9;
	printf("%d\n", nAns);


Exit0:

	return 0;
}







