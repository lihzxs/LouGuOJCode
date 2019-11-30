/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-5 16:39
//	Comment		:	OJ(P1760)
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
#include <sstream>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;






int main(int argc, char* argv[])
{
	int				nInputN;
	stringstream	szAns;
	string			szOutput;
	scanf("%d", &nInputN);
	szAns.precision(0);
	szAns << fixed << pow(2.0L, nInputN);
	szOutput = szAns.str();
	szOutput[szOutput.length() - 1]--;
	cout << szOutput << endl;






Exit0:
	return 0;
}