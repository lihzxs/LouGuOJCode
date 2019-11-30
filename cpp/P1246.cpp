/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-16 17:19
//	Comment		:	OJ(P1246)
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
map<string, int>		mpNum;
int						nCount = 1;

void DFS(string& szNow, int nLen, int nIndex)
{
	if (nIndex > nLen - 1)
	{
		mpNum[szNow] = nCount;
		nCount++;
		return;
	}
	int i;
	if (nIndex == 0)
		i = 'a';
	else
		i = szNow[nIndex - 1] + 1;
	for (; i <= 'z'; i++)
	{
		szNow[nIndex] = i;
		DFS(szNow, nLen, nIndex + 1);
	}
}



int main(int argc, char* argv[])
{
	string				szTemp;
	for (int i = 1; i <= 6; i++)
	{
		szTemp.clear();
		szTemp.resize(i);
		DFS(szTemp, i, 0);
	}
	cin >> szTemp;
	printf("%d", mpNum[szTemp]);
		



Exit0:

	return 0;
}