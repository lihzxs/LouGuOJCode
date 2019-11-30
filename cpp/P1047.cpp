// First.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	BYTE*				pbyTreeSituation	= NULL;
	int					nAns				= 0;
	int					nNum;
	int					nAreaNum;
	int					nStart;
	int					nEnd;



	bRetCode = scanf("%d%d", &nNum, &nAreaNum);
	PROCESS_ERROR(bRetCode);

	pbyTreeSituation = (BYTE*)malloc((nNum + 1) * sizeof(BYTE));
	PROCESS_ERROR(pbyTreeSituation);

	memset(pbyTreeSituation, 0, (nNum + 1) * sizeof(BYTE));




	for (int i = 0; i < nAreaNum; i++)
	{
		bRetCode = scanf("%d%d", &nStart, &nEnd);
		PROCESS_ERROR(bRetCode);
		for (int j = nStart; j <= nEnd; j++)
		{
			if (pbyTreeSituation[j] == 0)
			{
				pbyTreeSituation[j] = 1;
				nAns++;
			}
		}
	}///for (int i = 0; i < nAreaNum; i++)


	bRetCode = printf("%d\n", nNum - nAns + 1);
	PROCESS_ERROR(bRetCode);







Exit0:

	return 0;
}







