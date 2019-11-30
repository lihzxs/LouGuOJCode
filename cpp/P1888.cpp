/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 14:57
//	Comment		:	OJ(P1888)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
using namespace std;
#define  MAXNUM		10

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
	int		nA;
	int		nB;
	int		nC;
	int		nGcd;
	int		nAnsUp;
	int		nAnsDown;


	scanf("%d%d%d", &nA, &nB, &nC);

	if (nA > nB)
		swap(nA, nB);
	if (nB > nC)
		swap(nB, nC);

	if (nC < nB)
		swap(nC, nB);
	if (nB < nA)
		swap(nB, nA);

	nGcd = CalcGCD(nA, nC);

	printf("%d/%d\n", nA / nGcd, nC / nGcd);




	

Exit0:

	return 0;
}







