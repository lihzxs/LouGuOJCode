/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 20:25
//	Comment		:	OJ(P2911)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
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


typedef unsigned int       BYTE;
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

	int					nInputS1;
	int					nInputS2;
	int					nInputS3;
	int					nMaxCount		= 0;
	int					nMaxIndex		= 0;
	BYTE*				pbySeq			= NULL;

	pbySeq = (BYTE*)malloc(MAXNUM * sizeof(BYTE));
	memset(pbySeq, 0, MAXNUM * sizeof(BYTE));

	scanf("%d%d%d", &nInputS1, &nInputS2, &nInputS3);

	for(int i = 1; i <= nInputS1; i++)
		for (int j = 1; j <= nInputS2; j++)
			for (int z = 1; z <= nInputS3; z++)
				pbySeq[i + j + z]++;


	for (int i = MAXNUM - 1; i > 2; i--)
	{
		if (pbySeq[i] >= nMaxCount)
		{
			nMaxCount = pbySeq[i];
			nMaxIndex = i;
		}
	}


	printf("%d\n", nMaxIndex);


Exit0:

	return 0;
}







