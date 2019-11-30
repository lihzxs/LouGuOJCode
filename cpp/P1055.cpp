/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 15:20
//	Comment		:	OJ(P1055)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
#include <string>
using namespace std;
#define	MAXNUM		110
#define MODNUM		11

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



int main(int argc, char* argv[])
{
	string			szInput;
	int				nAns			= 0;
	int				nCount			= 0;
	cin >> szInput;


	for (int i = 0; i < szInput.length() - 1; i++)
	{
		if (szInput[i] == '-')
			continue;
		nCount++;
		nAns += nCount * (szInput[i] - '0');
		nAns %= MODNUM;
	}


	if (nAns == 10 ? (szInput[szInput.length() - 1] == 'X') : 
		(szInput[szInput.length() - 1] == nAns + '0'))
		printf("Right");
	else
	{
		if (nAns == 10)
			szInput[szInput.length() - 1] = 'X';
		else
			szInput[szInput.length() - 1] = nAns + '0';
		cout << szInput;
	}

Exit0:

	return 0;
}






