/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 15:46
//	Comment		:	OJ(P2955)
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
#define	MAXNUM		201
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


const double			gs_Pi = 3.14159265358979323;
int main(int argc, char* argv[])
{
	int			nNum;
	string		szTemp;


	scanf("%d", &nNum);

	for (int i = 0; i < nNum; i++)
	{
		cin >> szTemp;
		if ((szTemp[szTemp.length() - 1] - '0') % 2)
			printf("odd\n");
		else
			printf("even\n");
	}




Exit0:

	return 0;
}







