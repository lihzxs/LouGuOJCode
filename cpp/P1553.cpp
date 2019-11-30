/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-8 20:38
//	Comment		:	OJ(P1553)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


long long Reverse(string szNum)
{
	int i = 0;
	int j = szNum.length() - 1;
	while (i < j)
	{
		swap(szNum[i], szNum[j]);
		i++;
		j--;
	}
	return atoll(szNum.c_str());
}


int main(int argc, char* argv[])
{
	string			szInput;
	int				nRecord;
	long long		llTemp;
	cin >> szInput;
	if (szInput[szInput.length() - 1] == '%')
	{
		printf("%lld", Reverse(szInput.substr(0, szInput.length() - 1)));
		printf("%c", szInput[szInput.length() - 1]);
	}
	else
	{
		for (nRecord = 0; nRecord < szInput.length(); nRecord++)
		{
			if (szInput[nRecord] == '.' || szInput[nRecord] == '/')
				break;
		}
		if (nRecord == szInput.length())
			printf("%lld", Reverse(szInput));
		else if (szInput[nRecord] == '.')
		{
			printf("%lld", Reverse(szInput.substr(0,nRecord)));
			printf("%c", szInput[nRecord]);
			llTemp = Reverse(szInput.substr(nRecord + 1, szInput.length() - nRecord));
			while (llTemp % 10 == 0 && llTemp != 0)
				llTemp /= 10;
			printf("%lld", llTemp);
		}
		else
		{
			printf("%lld", Reverse(szInput.substr(0, nRecord)));
			printf("%c", szInput[nRecord]);
			printf("%lld", Reverse(szInput.substr(nRecord + 1, szInput.length() - nRecord)));
		}
	}
		
Exit0:

	return 0;
}