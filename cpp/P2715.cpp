/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 21:50
//	Comment		:	OJ(P2715)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	char			cTemp;
	string			szTemp;
	int				nNum[3];
	int				nCount = 0;
	int				nFlag;
	while (scanf("%c", &cTemp) != EOF)
	{
		if (isdigit(cTemp) || cTemp == '+' || cTemp == '-' ||
			cTemp == '*' || cTemp == '/' || cTemp == '=' || cTemp == '?')
			szTemp.push_back(cTemp);
	}

	for (int i = 0; i < szTemp.size(); i++)
	{
		if (szTemp[i] == '+')
			nFlag = 1;
		if (szTemp[i] == '-')
			nFlag = 2;
		if (szTemp[i] == '*')
			nFlag = 3;
		if (szTemp[i] == '/')
			nFlag = 4;
		if (isdigit(szTemp[i]))
		{
			int j;
			for (j = i + 1; j < szTemp.size(); j++)
				if (!isdigit(szTemp[j]))
					break;
			nNum[nCount++] = stoi(szTemp.substr(i, j - i));
			i = j - 1;
		}
		else if (szTemp[i] == '?')
			nNum[nCount++] = -1;
	}

	if (nNum[0] == -1)
	{
		if (nFlag == 1)
			printf("%.2f\n", nNum[2] * 1.0 - nNum[1]);
		if (nFlag == 2)
			printf("%.2f\n", nNum[2] * 1.0 + nNum[1]);
		if (nFlag == 3)
			printf("%.2f\n", nNum[2] * 1.0 / nNum[1]);
		if (nFlag == 4)
			printf("%.2f\n", nNum[2] * 1.0 * nNum[1]);
	}
	if (nNum[1] == -1)
	{
		if (nFlag == 1)
			printf("%.2f\n", nNum[2] * 1.0 - nNum[0]);
		if (nFlag == 2)
			printf("%.2f\n", nNum[0] * 1.0 - nNum[2]);
		if (nFlag == 3)
			printf("%.2f\n", nNum[2] * 1.0 / nNum[0]);
		if (nFlag == 4)
			printf("%.2f\n", nNum[0] * 1.0 / nNum[2]);
	}

	if (nNum[2] == -1)
	{
		if (nFlag == 1)
			printf("%.2f\n", nNum[0] * 1.0 + nNum[1]);
		if (nFlag == 2)
			printf("%.2f\n", nNum[0] * 1.0 - nNum[1]);
		if (nFlag == 3)
			printf("%.2f\n", nNum[0] * 1.0 * nNum[1]);
		if (nFlag == 4)
			printf("%.2f\n", nNum[0] * 1.0 / nNum[1]);
	}
	
Exit0:

	return 0;
}