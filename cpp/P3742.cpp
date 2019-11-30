/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 21:17
//	Comment		:	OJ(P3742)
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
	int			nStrLen;
	string		szInputX;
	string		szInputY;
	BYTE*		pszAns		= NULL;
	cin >> nStrLen;
	cin >> szInputX >> szInputY;
	
	pszAns = (BYTE*)malloc((nStrLen + 1) * sizeof(BYTE));

	for (int i = 0; i < nStrLen; i++)
	{
		if (szInputX[i] < szInputY[i] )
		{
			printf("-1\n");
			goto Exit0;
		}
		if (szInputX[i] == szInputY[i] )
		{
			pszAns[i] = szInputX[i];
		}
		else
		{
			pszAns[i] = szInputY[i];
		}
	}
	pszAns[nStrLen] = '\0';
	printf("%s\n", pszAns);



Exit0:

	return 0;
}







