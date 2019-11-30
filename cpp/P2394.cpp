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
	BOOL				bScanf			= false;
	BOOL				bPrint			= false;
	BOOL				bRetCode		= false;
	long double			fInput;

	bRetCode = scanf("%15Lf", &fInput);
	PROCESS_ERROR(bRetCode);
	bScanf = true;

	bRetCode = printf("%.8Lf", fInput / 23.0);
	PROCESS_ERROR(bRetCode);
	bPrint = true;


Exit0:

	return 0;
}





