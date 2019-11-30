/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-26 16:20
//	Comment		:	OJ(P3955)
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
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

bool IsTrue(BOOL* pbFlag, int nNum)
{
	while (nNum != 0)
	{
		if (!pbFlag[nNum % 10])
			return false;
		nNum /= 10;
	}
	return true;
}




int main(int argc, char* argv[])
{
	int							nInputN;
	int							nInputM;
	int							nInputTemp;
	int							nLenght;
	int							nRecord;
	int*						pnSeq			= NULL;
	int							nModNum			= 1;
	scanf("%d%d", &nInputN, &nInputM);
	pnSeq = (int*)malloc(nInputN * sizeof(int));
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nLenght, &nInputTemp);
		for (int i = 0; i < nLenght; i++)
			nModNum *= 10;
		for (nRecord = 0; nRecord < nInputN; nRecord++)
			if (pnSeq[nRecord] % nModNum == nInputTemp)
			{
				printf("%d\n", pnSeq[nRecord]);
				break;
			}
				

		if (nRecord == nInputN)
			printf("-1\n");

		nModNum = 1;
	}

Exit0:

	return 0;
}