/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 15:59
//	Comment		:	OJ(P4445)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
using namespace std;
#define	MAXNUM		10
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


/**
* @brief 输入两个整数求公约数
* @param a 第一个整数
* @param b 第二个整数
* @return 返回结果
*/
int CalcGCD(int a, int b)
{
	if (a%b == 0)
		return b;
	return CalcGCD(b, a%b);
}



int main(int argc, char* argv[])
{
	int			nNum;
	int			nPreNum			= 0;
	long		lAns			= 0;
	int			nInput;

	scanf("%d", &nNum);
	scanf("%d", &nInput);
	nPreNum = nInput;
	for (int i = 1; i < nNum; i++)
	{
		scanf("%d", &nInput);
		lAns += nPreNum > nInput ? nPreNum : nInput;
		nPreNum = nInput;
	}

	printf("%ld\n", lAns);


Exit0:

	return 0;
}







