/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-3 22:54
//	Comment		:	OJ(P1603)
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
	string*			pszJudge;
	int*			pnSeq;
	int				nCount		= 0;
	string			szInput;
	bool			IsPrint		= 0;
	pszJudge = new string[21];

	pszJudge[1] = "one";
	pszJudge[2] = "two";
	pszJudge[3] = "three";
	pszJudge[4] = "four";
	pszJudge[5] = "five";
	pszJudge[6] = "six";
	pszJudge[7] = "seven";
	pszJudge[8] = "eight";
	pszJudge[9] = "nine";
	pszJudge[10] = "ten";
	pszJudge[11] = "eleven";
	pszJudge[12] = "twelve";
	pszJudge[13] = "thirteen";
	pszJudge[14] = "fourteen";
	pszJudge[15] = "fifteen";
	pszJudge[16] = "sixteen";
	pszJudge[17] = "seventeen";
	pszJudge[18] = "eighteen";
	pszJudge[19] = "nineteen";
	pszJudge[20] = "twenty";

	pnSeq = (int*)malloc(6 * sizeof(int));

	while (cin >> szInput)
	{
		transform(szInput.begin(), szInput.end(), szInput.begin(), ::tolower);

		if (szInput == ".")
			break;
		if (szInput == "a")
			pnSeq[nCount++] = 1;

		if (szInput == "both")
			pnSeq[nCount++] = 2;

		if (szInput == "another")
			pnSeq[nCount++] = 1;

		if (szInput == "first")
			pnSeq[nCount++] = 1;

		if (szInput == "second")
			pnSeq[nCount++] = 2;

		if (szInput == "third")
			pnSeq[nCount++] = 3;


		for (int i = 1; i < 21; i++)
			if (szInput == pszJudge[i])
			{
				pnSeq[nCount++] = i;
				break;
			}

	}

	if (nCount == 0)
		printf("0\n");
	else
	{
		for (int i = 0; i < nCount; i++)
			pnSeq[i] = pnSeq[i] * pnSeq[i] % 100;

		sort(pnSeq, pnSeq + nCount);

		for (int i = 0; i < nCount; i++)
		{
			if (IsPrint == 0 && pnSeq[i] == 0)
				continue;
			else
			{
				if (IsPrint != 0 && pnSeq[i] < 10)
					printf("0");
				printf("%d", pnSeq[i]);
				IsPrint = 1;
			}
		}

		if (IsPrint == 0)
			printf("0");

		printf("\n");


	}

	
Exit0:
	return 0;
}