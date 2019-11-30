/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-28 22:32
//	Comment		:	OJ(P1691)
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

void DFS(int* pnWordCount, int nCount, int nNum, int& nAns, char* szOutput)
{
	/*for (int i = 0; i < 26; i++)
		cout << char(i + 'a') << " " << pnWordCount[i] << endl;
	cout << endl;*/
	if (nCount >= nNum)
	{
		szOutput[nNum] = '\0';
		printf("%s\n", szOutput);
		nAns++;
		return;
	}
	for (int i = 0; i < 26; i++)
	{
		if (pnWordCount[i] > 0)
		{
			pnWordCount[i]--;
			szOutput[nCount] = i + 'a';
			DFS(pnWordCount, nCount + 1, nNum, nAns, szOutput);
			pnWordCount[i]++;
		}
	}
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnWordCount				 = NULL;
	string			szInput;
	char			szOutput[600];
	int				nAns					= 0;
	pnWordCount = (int*)malloc(26 * sizeof(int));
	memset(pnWordCount, 0, 26 * sizeof(int));
	scanf("%d", &nInputN);

	cin >> szInput;
	for (int i = 0; i < szInput.length(); i++)
		pnWordCount[szInput[i] - 'a']++;

	DFS(pnWordCount, 0, nInputN, nAns, szOutput);

	printf("%d\n", nAns);
Exit0:

	return 0;
}