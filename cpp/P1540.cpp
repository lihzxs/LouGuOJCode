/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-24 00:08
//	Comment		:	OJ(P1540)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;






int main(int argc, char* argv[])
{
	int			nInputM;
	int			nInputN;
	BOOL*		pbFlag				= NULL;
	queue<int>	qNum;
	int			nRecord;
	int			nInputTemp;
	int			nAns				= 0;
	scanf("%d%d", &nInputM, &nInputN);

	pbFlag = (BOOL*)malloc(1010 * sizeof(int));

	memset(pbFlag, false, 1010 * sizeof(int));

	for (int nRecord = 0; nRecord < nInputN; nRecord++)
	{
		scanf("%d", &nInputTemp);
		if (pbFlag[nInputTemp])
			continue;
		else
		{
			if (nAns >= nInputM)
			{
				pbFlag[qNum.front()] = false;
				qNum.pop();
			}
			qNum.push(nInputTemp);
			pbFlag[nInputTemp] = true;
			nAns++;
		}
	}

	printf("%d", nAns);



			

Exit0:

	return 0;
}