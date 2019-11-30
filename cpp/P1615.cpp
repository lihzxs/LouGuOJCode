/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 22:34
//	Comment		:	OJ(P1615)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		100
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
	unsigned long long	ullAns;
	int					nStartHour;
	int					nStartMinute;
	int					nSatrtSecond;
	int					nEndHour;
	int					nEndMinute;
	int					nEndSecond;
	int					nSpeed;
	int					nSumSecond			= 0;

	scanf("%d:%d:%d", &nStartHour, &nStartMinute, &nSatrtSecond);
	scanf("%d:%d:%d", &nEndHour, &nEndMinute, &nEndSecond);
	scanf("%d", &nSpeed);

	if (nEndSecond < nSatrtSecond)
	{
		nSumSecond += 60 + nEndSecond - nSatrtSecond;
		nEndMinute--;
	}
	else
		nSumSecond +=  nEndSecond - nSatrtSecond;

	if (nEndMinute < nStartMinute)
	{
		nSumSecond += (60 + nEndMinute - nStartMinute) * 60;
		nEndHour--;
	}
	else
		nSumSecond += (nEndMinute - nStartMinute) * 60;

	nSumSecond += (nEndHour - nStartHour) * 3600;

	ullAns = nSpeed * nSumSecond;

	printf("%u\n", ullAns);





Exit0:

	return 0;
}







