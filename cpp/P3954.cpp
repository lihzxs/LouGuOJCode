/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 16:12
//	Comment		:	OJ(P3954)
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
	int			nScoreA;
	int			nScoreB;
	int			nScoreC;
	int			nAns;
	scanf("%d%d%d", &nScoreA, &nScoreB, &nScoreC);
	nAns = nScoreA * 0.2 + nScoreB * 0.3 + nScoreC * 0.5;
	printf("%d\n", nAns);


Exit0:

	return 0;
}







