/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-29 18:28
//	Comment		:	OJ(P1480)
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
	string			szNum1;
	int				nNum2;
	int				nPre					= 0;
	list<int>		lsNum;

	cin >> szNum1 >> nNum2;

	if (szNum1.length() <= 9)
		printf("%d", atoi(szNum1.c_str()) / nNum2);
	else
	{
		for (int i = 0; i < szNum1.length(); i++)
			szNum1[i] -= '0';
		for (int i = 0; i < szNum1.length(); i++)
		{
			lsNum.push_back((szNum1[i] + nPre * 10) / nNum2);
			nPre = (szNum1[i] + nPre * 10) % nNum2;
		}
		while (lsNum.front() == 0)
			lsNum.pop_front();
		while (!lsNum.empty())
		{
			printf("%d", lsNum.front());
			lsNum.pop_front();
		}
			

	}
	

Exit0:
	return 0;
}