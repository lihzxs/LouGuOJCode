/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-24 19:43
//	Comment		:	OJ(P2913)
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




int main(int argc, char* argv[])
{
	int				nInputN;
	map<int, int>	mapGear;
	int				nInputTemp1;
	int				nInputTemp2;
	int				nInputTemp3;
	BOOL*			pbLink;
	BOOL			bIsClockwise = true;

	scanf("%d", &nInputN);

	pbLink = (BOOL*)malloc((nInputN + 1) * sizeof(BOOL));

	for (int i = 1; i < nInputN; i++)
	{
		scanf("%d%d%d", &nInputTemp1, &nInputTemp2, &nInputTemp3);
		mapGear[nInputTemp1] = nInputTemp2;
		pbLink[nInputTemp1] = nInputTemp3;
	}


	nInputTemp1 = 1;
	while (nInputTemp1 != nInputN)
	{
		if (pbLink[nInputTemp1])
			bIsClockwise = !bIsClockwise;

		nInputTemp1 = mapGear[nInputTemp1];
	}

	printf("%d", !bIsClockwise);






			

Exit0:

	return 0;
}