/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 15:07
//	Comment		:	OJ(P4702)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
#include <string>
using namespace std;
#define	MAXNUM		110

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
	int		nIndex = 0;
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
	long long				lInputN;
	long long				lInputTemp;
	long long				lSum				= 0;

	scanf("%lld", &lInputN);
	
	for (int i = 0; i < lInputN; i++)
	{
		scanf("%lld", &lInputTemp);
		lSum += lInputTemp;
	}
	if (lSum % 2)
		printf("Alice");
	else
		printf("Bob");

Exit0:

	return 0;
}






