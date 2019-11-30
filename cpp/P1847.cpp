/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 10:01
//	Comment		:	OJ(P1847)
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
#define	MAXNUM		3000
#define	EPS         0.0001


#define ERROR_ID    0

#define PROCESS_ERROR(Condition)    \
{                                   \
        if (!(Condition))           \
        {                           \
            goto Exit0;             \
        }                           \
}


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{

	long long			nInputM;
	long long			nInputN;
	long long			nInputX1;
	long long			nInputX2;
	long long			nInputY1;
	long long			nInputY2;
	long long			nCount = 0;
	long long			nRecordCount = 0;
	long long*			pnX1 = NULL;
	long long*			pnX2 = NULL;
	long long*			pnY1 = NULL;
	long long*			pnY2 = NULL;
	long long			nAnsCount = 0;
	long long			nAnsIndex = 0;

	scanf("%lld%lld", &nInputM, &nInputN);


	pnX1 = (long long*)malloc(MAXNUM * sizeof(long long));
	pnX2 = (long long*)malloc(MAXNUM * sizeof(long long));
	pnY1 = (long long*)malloc(MAXNUM * sizeof(long long));
	pnY2 = (long long*)malloc(MAXNUM * sizeof(long long));

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%lld%lld%lld%lld", &nInputX1, &nInputY1, &nInputX2, &nInputY2);
		pnX1[nCount] = nInputX1;
		pnX2[nCount] = nInputX2;
		pnY1[nCount] = nInputY1;
		pnY2[nCount] = nInputY2;
		nCount++;

	}///for (int i = 0; i < nInputM; i++)

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%lld%lld", &nInputX1, &nInputY1);
		for (int j = 0; j < nCount; j++)
		{
			if (pnX1[j] <= nInputX1 &&
				pnX2[j] >= nInputX1 &&
				pnY1[j] <= nInputY1 &&
				pnY2[j] >= nInputY1)
			{
				nAnsCount++;
				nAnsIndex = j;
			}
		}
		if (!nAnsCount)
			printf("NO\n");
		else
			printf("YES %lld %lld\n", nAnsCount, nAnsIndex + 1);

		nAnsCount = 0;
		nAnsIndex = 0;
	}









Exit0:

	if (!pnX1)
		free(pnX1);
	if (!pnX2)
		free(pnX2);
	if (!pnY1)
		free(pnY1);
	if (!pnY2)
		free(pnY2);


	return 0;
}




