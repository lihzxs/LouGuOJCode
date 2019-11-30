/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-20 10:45
//	Comment		:	OJ(P2548)
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
using namespace std;
#define	MAXNUM		20000
#define	EPS         0.0001
#define DIRNUM		4
#define ERROR_ID    0

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	//ios::sync_with_stdio(false);

	int				nInputN;
	int				nInputM;
	int				nFlag = false;
	BOOL*			pbFlag = NULL;
	string**		ppszInput = NULL;

	scanf("%d%d", &nInputN, &nInputM);

	ppszInput = new string*[nInputM];

	for (int i = 0; i < nInputM; i++)
		ppszInput[i] = new string[nInputN];
	pbFlag = (BOOL*)malloc(nInputN * sizeof(BOOL));
	memset(pbFlag, false, nInputN * sizeof(BOOL));

	for (int i = 0; i < nInputM; i++)
		for (int j = 0; j < nInputN; j++)
		{
			ppszInput[i][j].resize(40);
			scanf("%s", &ppszInput[i][j][0]);
		}


	for (int i = 0; i < nInputN; i++)
		for (int j = 1; j < nInputM; j++)
		{
			if (ppszInput[j - 1][i] != ppszInput[j][i])
			{
				pbFlag[i] = true;
				break;
			}
		}

	for (int i = 0; i < nInputN; i++)
	{
		if (nFlag)
			printf(" ");
		else
			nFlag = true;

		if (!pbFlag[i])
			printf("%s", ppszInput[0][i].c_str());
		else
			printf("*");
	}
Exit0:

	return 0;
}

