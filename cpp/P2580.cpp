/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-19 21:52
//	Comment		:	OJ(P2580)
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
	//ios::sync_with_stdio(false);
	map<string, int> mpDic;
	string			szTemp;
	int				nInputN;
	int				nInputM;
	int				nTemp;
	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		cin >> szTemp;
		mpDic[szTemp] = 1;
	}
	
	scanf("%d", &nInputM);

	for (int i = 0; i < nInputM; i++)
	{
		cin >> szTemp;
		if (mpDic[szTemp] == 1)
		{
			printf("OK\n");
			mpDic[szTemp]++;
		}
		else if (mpDic[szTemp] == 2)
			printf("REPEAT\n");
		else
			printf("WRONG\n");
	}


Exit0:

	return 0;
}