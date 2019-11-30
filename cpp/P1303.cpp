/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-3 18:21
//	Comment		:	OJ(P1303)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	string			szNum1;
	string			szNum2;
	int*			pnNum1					= NULL;
	int*			pnNum2					= NULL;
	int*			pnOutput				= NULL;
	
	int				nOutputLen				= 0;
	int				nPre					= 0;
	cin >> szNum1 >> szNum2;

	pnNum1 = (int*)malloc((szNum1.length() + 1) * sizeof(int));
	pnNum2 = (int*)malloc((szNum2.length() + 1) * sizeof(int));
	for (int i = 0; i < szNum1.length(); i++)
		pnNum1[szNum1.length() - i] = szNum1[i] - '0';
	for (int i = 0; i < szNum2.length(); i++)
		pnNum2[szNum2.length() - i] = szNum2[i] - '0';

	pnOutput = (int*)malloc((szNum1.length() + szNum2.length() + 1) * 
		sizeof(int));
	memset(pnOutput, 0, (szNum1.length() + szNum2.length() + 1) *
		sizeof(int));
	
	for (int i = 1; i < szNum1.length() + 1; i++)
	{
		for (int j = 1; j < szNum2.length() + 1; j++)
		{
			pnOutput[i + j - 1] += pnNum1[i] * pnNum2[j] + nPre;
			nPre = pnOutput[i + j - 1] / 10;
			pnOutput[i + j - 1] %= 10;
		}
		pnOutput[szNum2.length() + i] = nPre;
		nPre = 0;
	}

	nOutputLen = szNum1.length() + szNum2.length();
	while (pnOutput[nOutputLen] == 0 && nOutputLen > 1)
		nOutputLen--;

	for (int i = nOutputLen; i >= 1; i--)
		printf("%d", pnOutput[i]);

Exit0:
	return 0;
}