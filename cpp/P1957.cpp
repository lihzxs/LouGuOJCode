/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-20 15:31
//	Comment		:	OJ(P1957)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		20000
#define	EPS         0.0001
#define DIRNUM		4
#define ERROR_ID    0

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int				nInputN;
	string			szInputTemp;
	char			szOne[100];
	char			szTwo[100];
	char			szTree[100];
	char			szTemp[100];
	string			szOutput			= "";
	int				nA;
	int				nB;
	int				nRecord;
	int				nPreOperate			= -1;

	scanf("%d", &nInputN);
	szInputTemp.resize(100);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%s", szOne);
		if (szOne[0] >= 'a' && szOne[0] <= 'c')
		{
			scanf("%s%s", szTwo, szTree);
			sprintf(&szInputTemp[0], "%s %s %s", szOne, szTwo, szTree);
		}
		else
		{
			scanf("%s", szTwo);
			sprintf(&szInputTemp[0], "%s %s", szOne, szTwo);
		}
		if (szInputTemp[0] >= 'a' && szInputTemp[0] <= 'c')
		{
			nPreOperate = szInputTemp[0] - 'a';
			for (nRecord = 2; nRecord < szInputTemp.length() &&
				szInputTemp[nRecord] != ' '; nRecord++);
			nA = atoi(szInputTemp.substr(2, nRecord).c_str());
			nB = atoi(szInputTemp.substr(nRecord + 1, 
				szInputTemp.length()).c_str());
			if (nPreOperate == 0)
				szOutput = to_string(nA) + "+" + to_string(nB) + 
				"=" + to_string(nA + nB);
			if (nPreOperate == 1)
				szOutput = to_string(nA) + "-" + to_string(nB) +
				"=" + to_string(nA - nB);
			if (nPreOperate == 2)
				szOutput = to_string(nA) + "*" + to_string(nB) +
				"=" + to_string(nA * nB);
			cout << szOutput << endl;
			cout << szOutput.length() << endl;
		}
		else
		{
			for (nRecord = 0; nRecord < szInputTemp.length() &&
				szInputTemp[nRecord] != ' '; nRecord++);
			nA = atoi(szInputTemp.substr(0, nRecord).c_str());
			nB = atoi(szInputTemp.substr(nRecord + 1,
				szInputTemp.length()).c_str());
			if (nPreOperate == 0)
				szOutput = to_string(nA) + "+" + to_string(nB) +
				"=" + to_string(nA + nB);
			if (nPreOperate == 1)
				szOutput = to_string(nA) + "-" + to_string(nB) +
				"=" + to_string(nA - nB);
			if (nPreOperate == 2)
				szOutput = to_string(nA) + "*" + to_string(nB) +
				"=" + to_string(nA * nB);
			cout << szOutput << endl;
			cout << szOutput.length() << endl;
		}
	}

	



	

Exit0:

	return 0;
}

