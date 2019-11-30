/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 23:47
//	Comment		:	OJ(P1960)
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
	map<string, string>		mp;
	int						nInputN;
	int						nInputQ;
	string					szX;
	string					szA;
	string					szB;
	string					szC;
	string					szD;
	scanf("%d%d", &nInputN, &nInputQ);

	for (int i = 0; i < nInputN; i++)
	{
		cin >> szA >> szB;
		mp[szA] = szB;
	}

	for (int i = 0; i < nInputQ; i++)
	{
		cin >> szX >> szA >> szB >> szC >> szD;
		if(mp[szX] == szA)
			printf("A\n");
		if(mp[szX] == szB)
			printf("B\n");
		if(mp[szX] == szC)
			printf("C\n");
		if(mp[szX] == szD)
			printf("D\n");
	}
	

Exit0:
	return 0;
}