/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-17 14:33
//	Comment		:	OJ(P1071)
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	string				szInputEncry;
	string				szInputinfo;
	string				szInput;
	int					nCount = 0;
	map<int, int>		mpDir;
	map<int, bool>		mpFlag;


	for (int i = 0 + 'A'; i < 26 + 'A'; i++)
		mpDir[i] = -1;

	cin >> szInputEncry;
	cin >> szInputinfo;
	cin >> szInput;

	for (int i = 0; i < szInputEncry.length(); i++)
	{
		if (mpDir[szInputEncry[i]] == -1)
			nCount++;
		else if (mpDir[szInputEncry[i]] != szInputinfo[i])
		{
			printf("Failed");
			return 0;
		}
		mpDir[szInputEncry[i]] = szInputinfo[i];
		mpFlag[szInputinfo[i]] = true;
	}
	for (int i = 0 + 'A'; i < 26 + 'A'; i++)
	{
		if (!mpFlag[i])
		{
			printf("Failed");
			return 0;
		}
	}
	if (nCount < 26)
		printf("Failed");
	else
	{
		for (int i = 0; i < szInput.length(); i++)
			printf("%c", mpDir[szInput[i]]);
	}


Exit0:

	return 0;
}