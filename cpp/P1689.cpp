/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-5 19:23
//	Comment		:	OJ(P1689)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>
#include <sstream>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	string				szInput				= "";
	string				szTemp;
	int					nOpIndex;
	int					nEqualIndex;
	int					nAnsIndex;
	long long			nFirstNum			= -1;
	long long			nSecondNum			= -1;
	long long			nAnsNum				= -1;

		while (cin >> szTemp)
		szInput += szTemp;

	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] == '+' || szInput[i] == '-')
			nOpIndex = i;
		if (szInput[i] == '=')
			nEqualIndex = i;
		if (szInput[i] == '?')
			nAnsIndex = i;
	}


	if (nOpIndex < nEqualIndex)
	{
		if (nAnsIndex > nOpIndex)
			nFirstNum = atoll(szInput.substr(0, nOpIndex).c_str());
		if (nAnsIndex < nOpIndex || nAnsIndex > nEqualIndex)
			nSecondNum = atoll(szInput.substr(nOpIndex + 1,
				nEqualIndex - nOpIndex).c_str());
		if (nAnsIndex < nEqualIndex)
			nAnsNum = atoll(szInput.substr(nEqualIndex + 1,
				szInput.length() - nEqualIndex).c_str());

	}
	else
	{
		if (nAnsIndex < nEqualIndex || nAnsIndex > nOpIndex)
			nFirstNum = atoll(szInput.substr(nEqualIndex + 1, 
				nOpIndex - nEqualIndex).c_str());
		if (nAnsIndex < nOpIndex)
			nSecondNum = atoll(szInput.substr(nOpIndex + 1,
				szInput.length() - nOpIndex).c_str());
		if (nAnsIndex > nEqualIndex)
			nAnsNum = atoll(szInput.substr(0,
				nEqualIndex).c_str());
	}
	
	if (nAnsNum == -1)
	{
		if (szInput[nOpIndex] == '+')
			printf("%lld", nFirstNum + nSecondNum);
		else
			printf("%lld", nFirstNum - nSecondNum);
	}
	if (nFirstNum == -1)
	{
		if (szInput[nOpIndex] == '+')
			printf("%lld", nAnsNum - nSecondNum);
		else
			printf("%lld", nAnsNum + nSecondNum);
	}
	if (nSecondNum == -1)
	{
		if (szInput[nOpIndex] == '+')
			printf("%lld", nAnsNum - nFirstNum);
		else
			printf("%lld", nFirstNum - nAnsNum);
	}
		

Exit0:
	return 0;
}