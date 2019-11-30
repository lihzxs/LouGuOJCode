/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-26 14:21
//	Comment		:	OJ(P2021)
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




int main(int argc, char* argv[])
{
	int					nInputN;
	list<int>			listSeq;
	int					nInputTemp;
	int*				pnOutput				= NULL;
	int*				pnTemp					= NULL;
	scanf("%d", &nInputN);
	pnOutput = (int*)malloc(nInputN * sizeof(int));
	pnTemp = (int*)malloc(nInputN * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
		listSeq.push_back(i);

	for (int i = 0; !listSeq.empty(); i++)
	{
		listSeq.push_back(listSeq.front());
		listSeq.pop_front();
		pnTemp[i] = listSeq.front() - 1;
		listSeq.pop_front();
	}

	for (int i = 0; i < nInputN; i++)
		pnOutput[pnTemp[i]] = i;

	for (int i = 0; i < nInputN; i++)
		printf("%d ", pnOutput[i] + 1);

		













Exit0:

	return 0;
}