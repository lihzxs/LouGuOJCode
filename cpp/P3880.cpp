/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-9 21:02
//	Comment		:	OJ(P2880)
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


bool Check(char cTemp)
{
	if (cTemp == 'a')
		return true;
	if (cTemp == 'e')
		return true;
	if (cTemp == 'i')
		return true;
	if (cTemp == 'o')
		return true;
	if (cTemp == 'u')
		return true;
	if (cTemp == 'A')
		return true;
	if (cTemp == 'E')
		return true;
	if (cTemp == 'I')
		return true;
	if (cTemp == 'O')
		return true;
	if (cTemp == 'U')
		return true;
	return false;
}



int main(int argc, char* argv[])
{
	string			szInput;
	string			szAns;
	int				nCount				= 0;
	int				nSecond;
	int				nThird;
	int             nF;
	//cin >> szInput;
	getline(cin, szInput);
	for (int i = 0; i < szInput.length(); i++)
	{
		if (isalpha(szInput[i]))
		{
			printf(".");
			nCount++;
		}
		else
			printf("%c", szInput[i]);
	}
	printf("\n");

	nSecond = (int)(nCount * 1.0 / 3 + 0.5);
	nThird = (int)(nCount * 2.0 / 3 + 0.5);
	nCount = 0;

	for (int i = 0; i < szInput.length(); i++)
	{
		if (isalpha(szInput[i]))
		{
			if (nCount < nSecond)
				printf("%c", szInput[i]);
			else
				printf(".");
			nCount++;
		}
		else
			printf("%c", szInput[i]);
	}
	printf("\n");


	nCount = 0;
	nF = 0;
	for (int i = 0; i < szInput.length(); i++)
	{
		if (isalpha(szInput[i]))
		{
			if (nCount >= nSecond && Check(szInput[i]))
			{
				nF = 1;
				break;
			}
			nCount++;
		}
	}
	nCount = nF;
	if (nCount == 0)
	{
		for (int i = 0; i < szInput.length(); i++)
		{
			if (isalpha(szInput[i]))
			{
				if (nCount < nThird)
					printf("%c", szInput[i]);
				else
					printf(".");
				nCount++;
			}
			else
				printf("%c", szInput[i]);
		}
	}
	else
	{
		nCount = 0;
		for (int i = 0; i < szInput.length(); i++)
		{
			if (isalpha(szInput[i]))
			{
				if (nCount < nSecond)
					printf("%c", szInput[i]);
				else if (Check(szInput[i]))
					printf("%c", szInput[i]);
				else
					printf(".");
				nCount++;
			}
			else
				printf("%c", szInput[i]);
		}
	}


Exit0:

	return 0;
}