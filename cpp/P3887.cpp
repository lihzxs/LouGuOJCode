/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-29 22:23
//	Comment		:	OJ(P3887)
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



int main(int argc, char* argv[])
{
	int					nInputK;
	priority_queue<int>	qK;
	int					nInputD;
	priority_queue<int>	qD;
	int					nInputM;
	priority_queue<int>	qM;
	int					nInputF;
	priority_queue<int>	qF;
	int					nInputTemp;
	int					nInputQ;
	int					nDNum;
	int					nMNum;
	int					nFNum;
	int					nSum				= 0;
	scanf("%d%d%d%d", &nInputK, &nInputD, &nInputM, &nInputF);


	for (int i = 0; i < nInputK; i++)
	{
		scanf("%d", &nInputTemp);
		qK.push(nInputTemp);
	}
	for (int i = 0; i < nInputD; i++)
	{
		scanf("%d", &nInputTemp);
		qD.push(nInputTemp);
	}
	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d", &nInputTemp);
		qM.push(nInputTemp);
	}
	for (int i = 0; i < nInputF; i++)
	{
		scanf("%d", &nInputTemp);
		qF.push(nInputTemp);
	}

	scanf("%d", &nInputQ);

	for (int i = 0; i < nInputQ; i++)
	{
		scanf("%d%d%d", &nDNum, &nMNum, &nFNum);
		nSum += qK.top();
		qK.pop();

		for (int j = 0; j < nDNum; j++)
		{
			nSum += qD.top();
			qD.pop();
		}
		for (int j = 0; j < nMNum; j++)
		{
			nSum += qM.top();
			qM.pop();
		}
		for (int j = 0; j < nFNum; j++)
		{
			nSum += qF.top();
			qF.pop();
		}
		
		printf("%.2f\n", nSum * 1.0 / (nDNum + nMNum + nFNum + 1));
		nSum = 0;
	}




Exit0:

	return 0;
}