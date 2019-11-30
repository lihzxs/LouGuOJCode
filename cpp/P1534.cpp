/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 15:20
//	Comment		:	OJ(P1534)
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
	int			nNum;
	int			nStudentTime;
	int			nTutor;
	int			nAns			= 0;
	int			nPreNotHappy	= 0;
	int			nNowNotHappy	= 0;


	scanf("%d", &nNum);
	for (int i = 0; i < nNum; i++)
	{
		scanf("%d%d", &nStudentTime, &nTutor);
		nNowNotHappy = nPreNotHappy + nStudentTime + nTutor - 8;
		nAns += nNowNotHappy;
		nPreNotHappy = nNowNotHappy;

	}

	printf("%d\n", nAns);




	

Exit0:

	return 0;
}







