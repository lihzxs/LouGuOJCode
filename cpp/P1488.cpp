/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 16:27
//	Comment		:	OJ(P1488)
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
#include <set>
using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	BOOL*			pbIsBlack				= NULL;
	int				nCountTri				= 0;
	int				nCountPoi				= 0;
	int				nA;
	int				nB;
	int				nC;

	scanf("%d", &nInputN);

	pbIsBlack = (BOOL*)malloc(nInputN * sizeof(BOOL));
	memset(pbIsBlack, 0, nInputN * sizeof(BOOL));

	scanf("%d%d%d", &nA, &nB, &nC);
	pbIsBlack[nA] = true;
	pbIsBlack[nB] = true;
	pbIsBlack[nC] = true;

	for (int i = 1; i < nInputN - 2; i++)
	{
		scanf("%d%d%d", &nA, &nB, &nC);
		
		if (pbIsBlack[nA])
			nCountPoi++;
		if (pbIsBlack[nB])
			nCountPoi++;
		if (pbIsBlack[nC])
			nCountPoi++;

		if (nCountPoi >= 2)
			nCountTri++;

	}

	if (nCountTri < 2)
		printf("JMcat Win");
	else
	{
		if ((nInputN - 2) % 2)
			printf("PZ Win");
		else
			printf("JMcat Win");
	}


Exit0:

	return 0;
}