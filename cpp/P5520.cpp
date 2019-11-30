/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-23 22:58
//	Comment		:	OJ(P5520)
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

	long long				llInputN;
	long long				llInputM;
	long long				llInputMod;
	long long				llAns				= 1;
	scanf("%lld", &llInputN);
	scanf("%lld%lld%lld", &llInputN, &llInputM, &llInputMod);

	for (int i = llInputN - 2 * llInputM + 2;
		i <= llInputN - llInputM + 1; i++)
		llAns = llAns * i % llInputMod;

	printf("%lld", llAns);
Exit0:

	return 0;
}