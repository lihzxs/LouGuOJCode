/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 16:38
//	Comment		:	OJ(P1046)
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
	unsigned int*		punSeq			= NULL;
	int					nAns			= 0;
	int					nHeight;
	punSeq = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int*));

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", punSeq + i);
	}

	scanf("%d", &nHeight);
	nHeight += 30;

	for (int i = 0; i < 10; i++)
	{
		if (nHeight >= punSeq[i])
			nAns++;
	}

	printf("%d\n", nAns);


Exit0:

	return 0;
}







