/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-12 21:19
//	Comment		:	OJ(P1881)
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
#include <list>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




bool Check(int nLeft, int nRight, int nL, map<int, bool>& mpFlag)
{
	while (nLeft >= 0 && nRight <= nL)
	{
		if (mpFlag[nLeft] != mpFlag[nRight])
			return false;
		nLeft--;
		nRight++;
	}

	return true;
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputL;
	int*			pnSeq = NULL;
	int				nTemp;
	map<int, bool>	mpFlag;
	int				nAddItem;
	int				nAns = 0;
	//scanf("%d%d", &nInputN, &nInputL);
	cin >> nInputN >> nInputL;
	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		mpFlag[pnSeq[i]] = true;
	}


	sort(pnSeq, pnSeq + nInputN);

	for (int i = 0; i < nInputN - 1; i++)
		nAns += Check(pnSeq[i], pnSeq[i + 1], nInputL, mpFlag);


	for (int i = 1; i < nInputN - 1; i++)
		nAns += Check(pnSeq[i] - 1, pnSeq[i] + 1, nInputL, mpFlag);

	//printf("%d", nAns);
	cout << nAns << endl;

Exit0:

	return 0;
}