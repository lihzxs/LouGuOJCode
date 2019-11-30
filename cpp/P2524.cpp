/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 23:47
//	Comment		:	OJ(P1960)
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
	int					nInputN;
	char*				pnSeq			= NULL;
	int					nAns			= 0;
	//scanf("%d", &nInputN);
	cin >> nInputN;
	pnSeq = (char*)malloc(nInputN * sizeof(char));

	for(int i = 0; i < nInputN; i++)
	{
		//scanf("%c", pnSeq + i);
		cin >> pnSeq[i];
		pnSeq[i] -= '0';
	}
		

	while(prev_permutation(pnSeq, pnSeq + nInputN))
		nAns++;
	printf("%d", nAns + 1);

Exit0:
	return 0;
}