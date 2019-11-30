/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-1 14:16
//	Comment		:	OJ(P1206)
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


bool IsPalindrome(string& szTemp)
{
	int i = 0;
	int j = szTemp.length() - 1;
	while (i < j)
	{
		if (szTemp[i] != szTemp[j])
			return false;
		i++;
		j--;
	}
	return true;
}


int main(int argc, char* argv[])
{
	int				nInputN;
	string			szTemp;
	string			szAddItem;
	stack<int>		sOutput;
	int				nTemp;
	scanf("%d", &nInputN);

	for (int i = 1; i <= 300; i++)
	{
		szTemp = "";
		nTemp = i * i;
		while (nTemp)
		{
			if (nTemp % nInputN < 10)
				szAddItem = to_string(nTemp % nInputN);
			if (nTemp % nInputN == 10)
				szAddItem = "A";
			if (nTemp % nInputN == 11)
				szAddItem = "B";
			if (nTemp % nInputN == 12)
				szAddItem = "C";
			if (nTemp % nInputN == 13)
				szAddItem = "D";
			if (nTemp % nInputN == 14)
				szAddItem = "E";
			if (nTemp % nInputN == 15)
				szAddItem = "F";
			if (nTemp % nInputN == 16)
				szAddItem = "G";
			if (nTemp % nInputN == 17)
				szAddItem = "H";
			if (nTemp % nInputN == 18)
				szAddItem = "I";
			if (nTemp % nInputN == 19)
				szAddItem = "J";
			szTemp += szAddItem;
			nTemp /= nInputN;
		}
		if (IsPalindrome(szTemp))
		{
			nTemp = i;
			while (nTemp)
			{
				sOutput.push(nTemp % nInputN);
				nTemp /= nInputN;
			}

			while (!sOutput.empty())
			{
				if (sOutput.top() < 10)
					szAddItem = to_string(sOutput.top());
				if (sOutput.top() == 10)
					szAddItem = "A";
				if (sOutput.top() == 11)
					szAddItem = "B";
				if (sOutput.top() == 12)
					szAddItem = "C";
				if (sOutput.top() == 13)
					szAddItem = "D";
				if (sOutput.top() == 14)
					szAddItem = "E";
				if (sOutput.top() == 15)
					szAddItem = "F";
				if (sOutput.top() == 16)
					szAddItem = "G";
				if (sOutput.top() == 17)
					szAddItem = "H";
				if (sOutput.top() == 18)
					szAddItem = "I";
				if (sOutput.top() == 19)
					szAddItem = "J";

				cout << szAddItem;
				sOutput.pop();
			}
			cout << " " << szTemp << endl;
		}

	}
Exit0:

	return 0;
}