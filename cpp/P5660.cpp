/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-26 19:12
//	Comment		:	OJ(P5560)
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

	string			szTemp;
	int				nAns = 0;
	cin >> szTemp;

	for (int i = 0; i < szTemp.length(); i++)
		if (szTemp[i] == '1')
			nAns++;

	cout << nAns;





Exit0:
	return 0;
}