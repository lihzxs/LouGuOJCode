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


BOOL CountSortChange(int* pSeq, int nNum, long* pChangeTime);

int main(int argc, char* argv[])
{

	BOOL			bScanf			= false;
	BOOL			bPrint			= false;
	BOOL			bRetCode		= false;
	int*			pSeq			= NULL;
	int				nNum			= 0;
	long			lChangeTime		= 0;

	bRetCode = scanf("%d", &nNum);
	PROCESS_ERROR(bRetCode);
	pSeq = (int*)malloc(nNum * sizeof(int));
	PROCESS_ERROR(pSeq);
	for (int i = 0; i < nNum; i++)
	{
		bRetCode = scanf("%d", pSeq + i);
		PROCESS_ERROR(bRetCode);
	}
	bScanf = true;


	bRetCode = CountSortChange(pSeq, nNum, &lChangeTime);
	PROCESS_ERROR(bRetCode);

	printf("%ld\n", lChangeTime);
	bPrint = true;

	


Exit0:
	if (pSeq)
		free(pSeq);
	return 0;
}



BOOL CountSortChange(int* pSeq, int nNum, long* pChangeTime)
{
	PROCESS_ERROR(pSeq);
	PROCESS_ERROR(pChangeTime);

	for (int i = 1; i < nNum; i++)
	{
		for (int j = 0; j < nNum - i; j++)
		{
			if (pSeq[j] > pSeq[j + 1])
			{
				swap(pSeq[j], pSeq[j + 1]);
				(*pChangeTime)++;
			}
		}
	}///for (int i = 0; i < nNum; i++)

	return true;
Exit0:
	return false;
}


