// First.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MAXNUM 10001
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


BOOL ReduceSeq(BYTE* pbyStr, int* pnAns);
int main(int argc, char* argv[])
{
	BOOL				bScanf			= false;
	BOOL				bPrint			= false;
	BOOL				bRetCode		= false;
	BYTE*				pbyInput;
	int					nAns;
	

	pbyInput = (BYTE*)malloc(MAXNUM * sizeof(BYTE));
	PROCESS_ERROR(pbyInput);

	bRetCode = scanf("%s", pbyInput);
	PROCESS_ERROR(bRetCode);
	bScanf = true;

	bRetCode = ReduceSeq(pbyInput, &nAns);
	PROCESS_ERROR(bRetCode);

	printf("%d\n", nAns);
	bPrint = true;






Exit0:

	return 0;
}


BOOL ReduceSeq(BYTE* pbyStr, int* pnAns)
{
	BYTE				byTemp = pbyStr[0];
	int					nStrLen = 1;

	PROCESS_ERROR(pbyStr && pnAns);
	*pnAns = 0;
	
	for (int i = 1; pbyStr[i] != '\0'; i++)
	{
		if (pbyStr[i] != byTemp)
			byTemp = pbyStr[i];
		else
			(*pnAns)++;
		nStrLen++;
	}

	*pnAns = nStrLen - 1 - *pnAns;
	if (byTemp == '0')
		(*pnAns)++;
	return true;

Exit0:
	return false;
}




