/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-24 16:50
//	Comment		:	OJ(P1755)
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

using namespace std;
#define	MAXNUM		1000000001
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int Init(long* plSeq)
{
	int				nRecord;
	plSeq[0] = 0;
	plSeq[1] = 1;
	plSeq[2] = 1;

	for (nRecord = 3; plSeq[nRecord - 1] < MAXNUM; nRecord++)
		plSeq[nRecord] = plSeq[nRecord - 1] + plSeq[nRecord - 2];

	return nRecord - 1;

}




int main(int argc, char* argv[])
{
	int				nInputN;
	int				nRecord;
	int				nInputTemp;
	long			lSum				= 0;
	long*			plSeq				= NULL;
	stack<long>		sOutput;


	scanf("%d", &nInputN);

	plSeq = (long*)malloc(100 * sizeof(long));

	nRecord = Init(plSeq);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		printf("%d=", nInputTemp);

		for (int j = nRecord; j > 0; j--)
		{
			while (nInputTemp >= plSeq[j])
			{
				nInputTemp -= plSeq[j];
				sOutput.push(plSeq[j]);
			}
			if (nInputTemp <= 0)
				break;
		}
		printf("%d", sOutput.top());
		sOutput.pop();
		while (!sOutput.empty())
		{
			printf("+%d", sOutput.top());
			sOutput.pop();
		}
		printf("\n");


	}




			

Exit0:

	return 0;
}