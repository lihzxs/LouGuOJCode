// First.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

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



int main(int argc, char* argv[])
{
	BOOL				bScanf				= false;
	BOOL				bPrint				= false;
	BOOL				bRetCode			= false;
	long double			lfSum				= 0;
	long double			lfInput;
	

	while (scanf("%Lf", &lfInput) != EOF)
	{
		lfSum += lfInput * 1000000;
	}


	printf("%.5Lf\n", lfSum / 1000000);









Exit0:

	return 0;
}







