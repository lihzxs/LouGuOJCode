/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 11:24
//	Comment		:	OJ(P1482)
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
using namespace std;
#define	MAXNUM		27
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
	int			nFractionUp1;
	int			nFractionDown1;
	int			nFractionUp2;
	int			nFractionDown2;
	int			nAnsFractionUp;
	int			nAnsFractionDown;

	scanf("%d/%d", &nFractionUp1, &nFractionDown1);
	scanf("%d/%d", &nFractionUp2, &nFractionDown2);


	nAnsFractionUp = nFractionUp1 * nFractionUp2;
	nAnsFractionDown = nFractionDown1 * nFractionDown2;

	printf("%d %d\n", nAnsFractionDown / CalcGCD(nAnsFractionUp, nAnsFractionDown),
		nAnsFractionUp / CalcGCD(nAnsFractionUp, nAnsFractionDown));




Exit0:

	return 0;
}







