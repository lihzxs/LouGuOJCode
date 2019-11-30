/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-4 23:50
//	Comment		:	OJ(P2786)
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
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

	int					nInputN;
	long long					nInputP;
	char				cTemp[1000];
	char				c;
	map<string, long long>	mpAdd;
	string				szTemp;
	string				szSub;
	int					nPre;
	long long					nNum;
	long long			nAns				= 0;

	
	scanf("%d%lld", &nInputN, &nInputP);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%s", cTemp);
		szTemp = cTemp;
		scanf("%lld", &nNum);
		mpAdd[szTemp] = nNum;
	}


	szTemp.clear();
	while (scanf("%c", &c) != EOF)
	{
		if (!isalpha(c) && !isdigit(c))
		{
			nAns += mpAdd[szTemp];
			nAns %= nInputP;
			szTemp.clear();
		}
		else
			szTemp.push_back(c);
	}

	printf("%lld", nAns);


Exit0:
	return 0;
}