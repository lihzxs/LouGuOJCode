/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 16:59
//	Comment		:	OJ(P1184)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
#include <set>
using namespace std;
#define	MAXNUM		3
#define	EPS         0.0001

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	string				szInput;
	set<string>			setPlace;
	int					nAns = 0;
	int					nInputN;
	int					nInputM;

	scanf("%d%d", &nInputN, &nInputM);
	
	getline(cin, szInput);
	for (int i = 0; i < nInputN; i++)
	{
		getline(cin, szInput);
		if (szInput[szInput.length() - 1] != (char)13)
			szInput = szInput + char(13);
		setPlace.insert(szInput);
	}

	for (int i = 0; i < nInputM; i++)
	{
		getline(cin, szInput);
		if (szInput[szInput.length() - 1] != (char)13)
			szInput = szInput + char(13);
		if (setPlace.find(szInput) != setPlace.end())
			nAns++;
	}

	printf("%d", nAns);

Exit0:

	return 0;
}