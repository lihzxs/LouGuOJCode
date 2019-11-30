/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 15:42
//	Comment		:	OJ(P1423)
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
	double		fLength;
	double		fPreLen		= 2;
	double		fSwimLen	= 2;
	int			nAns		= 1;

	scanf("%lf", &fLength);
	while (fSwimLen < fLength)
	{
		nAns++;
		fPreLen = fPreLen * 0.98;
		fSwimLen += fPreLen ;
	}

	printf("%d\n", nAns);


Exit0:

	return 0;
}







