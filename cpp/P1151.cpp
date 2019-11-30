/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 19:29
//	Comment		:	OJ(1151)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
using namespace std;
#define	MAXNUM		1000000001
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

void PrimeInit(unsigned int* punSeq, BYTE* pbyIsPrime)
{
	int		nIndex		= 0;
	memset(pbyIsPrime, 1, MAXNUM * sizeof(BYTE*));
	for (int i = 2; i*i < MAXNUM; i++)
	{
		if (pbyIsPrime[i])
		{
			punSeq[nIndex++] = i;
			for (int j = i * 2; j < MAXNUM; j += i)
				pbyIsPrime[j] = 0;
		}
	}
}



int main(int argc, char* argv[])
{

	int					nKNum;
	BOOL				bPrintFlag			= false;
	int					nSubNum1;
	int					nSubNum2;
	int					nSubNum3;

	scanf("%d", &nKNum);

	for (int i = 10000; i <= 30000; i++)
	{
		nSubNum1 = i / 100;
		nSubNum2 = i / 10 % 1000;
		nSubNum3 = i % 1000;

		if (nSubNum1 % nKNum == 0 &&
			nSubNum2 % nKNum == 0 &&
			nSubNum3 % nKNum == 0)
		{
			printf("%d\n", i);
			bPrintFlag = true;
		}
	}
	if (!bPrintFlag)
		printf("No\n");

	


Exit0:

	return 0;
}







