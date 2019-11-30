/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-23 21:54
//	Comment		:	OJ(P1067)
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



bool IsExist(string& szStr, string& szSubstr)
{
	int			nRecord			= 0;
	for (int i = 0; i < szStr.length(); i++)
	{
		if (szSubstr[nRecord] == szStr[i])
			nRecord++;
	}
	return nRecord == szSubstr.length();
}




int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputNum;
	string			szOutput			= "";
	BOOL			bIsFirst			= true;
	scanf("%d", &nInputN);

	for (int i = nInputN; i >= 0; i--)
	{
		scanf("%d", &nInputNum);
		if (nInputNum == 0)
			continue;
		if (bIsFirst)
		{
			if (i == 1)
			{
				if (nInputNum == 1)
					szOutput += "x";
				else if (nInputNum == -1)
					szOutput += "-x";
				else
					szOutput += to_string(nInputNum) + "x";
			}
			else
			{
				if (nInputNum == 1)
					szOutput += "x^" + to_string(i);
				else if (nInputNum == -1)
					szOutput += "-x^" + to_string(i);
				else
					szOutput += to_string(nInputNum) + "x^" + to_string(i);
			}

		}
		else
		{
			if (i == 0)
			{
				if (nInputNum > 0)
					szOutput += "+" + to_string(nInputNum);
				else
					szOutput += to_string(nInputNum);
			}
			else if(i == 1)
			{
				if (nInputNum == 1)
					szOutput += "+x";
				else if (nInputNum == -1)
					szOutput += "-x";
				else if (nInputNum > 1)
					szOutput += "+" + to_string(nInputNum) + "x";
				else
					szOutput += to_string(nInputNum) + "x";
			}
			else if (nInputNum == 1)
				szOutput += "+x^" + to_string(i);
			else if (nInputNum == -1)
				szOutput += "-x^" + to_string(i);
			else if (nInputNum > 1)
				szOutput += "+" + to_string(nInputNum) + "x^" + to_string(i);
			else if (nInputNum < -1)
				szOutput += to_string(nInputNum) + "x^" + to_string(i);
		}





		bIsFirst = false;
	}

	cout << szOutput << endl;



Exit0:

	return 0;
}