/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-11 22:07
//	Comment		:	OJ(P2645)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int						nInputN;
	int						nInputM;
	int						nAnsA			= 0;
	int						nCountRed		= 0;
	int						nAnsB			= 0;
	int						nPre			= 0;
	int						nTemp;
	scanf("%d%d", &nInputN, &nInputM);
	
	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", &nTemp);
		nAnsA += nTemp;
	}
	if (nTemp == 0)
		nAnsB += 4;
	for (int i = 1; i <= nInputM; i++)
	{
		scanf("%d", &nTemp);
		nAnsB += nTemp;
	}
	if (nTemp == 0)
		nAnsA += 4;
	printf("%d %d", nAnsA, nAnsB);


Exit0:

	return 0;
}