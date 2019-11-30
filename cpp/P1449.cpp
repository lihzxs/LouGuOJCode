/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-28 16:46
//	Comment		:	OJ(P1449)
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

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;






int main(int argc, char* argv[])
{
	
	string				szInput;
	long long			llSum				 = 0;
	stack<long long>	sNum;
	int					nRecord;

	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] == '.')
		{
			for (nRecord = i - 1; nRecord >= 0 && szInput[nRecord] >= '0' &&
				szInput[nRecord] <= '9'; nRecord--);
			sNum.push(atoll(szInput.substr(nRecord + 1, i).c_str()));
		}
		else if (szInput[i] == '+')
		{
			llSum = sNum.top();
			sNum.pop();
			llSum += sNum.top();
			sNum.pop();
			sNum.push(llSum);
		}
		else if (szInput[i] == '-')
		{
			llSum = sNum.top();
			sNum.pop();
			llSum = sNum.top() - llSum;
			sNum.pop();
			sNum.push(llSum);
		}
		else if (szInput[i] == '*')
		{
			llSum = sNum.top();
			sNum.pop();
			llSum *= sNum.top();
			sNum.pop();
			sNum.push(llSum);
		}
		else if (szInput[i] == '/')
		{
			llSum = sNum.top();
			sNum.pop();
			llSum = sNum.top() / llSum;
			sNum.pop();
			sNum.push(llSum);
		}
		else if (szInput[i] == '@')
			break;
	}

	cout << sNum.top() << endl;











Exit0:

	return 0;
}