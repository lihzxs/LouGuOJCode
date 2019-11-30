/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 22:33
//	Comment		:	OJ(P4122)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;








int main(int argc, char* argv[])
{

	int			nInputRec1X1;
	int			nInputRec1Y1;
	int			nInputRec1X2;
	int			nInputRec1Y2;
	int			nInputRec2X1;
	int			nInputRec2Y1;
	int			nInputRec2X2;
	int			nInputRec2Y2;
	int			nInputRec3X1;
	int			nInputRec3Y1;
	int			nInputRec3X2;
	int			nInputRec3Y2;

	int**		ppnMat			= NULL;
	int			nAns			= 0;


	scanf("%d%d%d%d", &nInputRec1X1, &nInputRec1Y1, &nInputRec1X2, &nInputRec1Y2);
	scanf("%d%d%d%d", &nInputRec2X1, &nInputRec2Y1, &nInputRec2X2, &nInputRec2Y2);
	scanf("%d%d%d%d", &nInputRec3X1, &nInputRec3Y1, &nInputRec3X2, &nInputRec3Y2);

	ppnMat = (int**)malloc(2500 * sizeof(int*));

	for (int i = 0; i < 2500; i++)
	{
		ppnMat[i] = (int*)malloc(2500 * sizeof(int));
		memset(ppnMat[i], 0, 2500 * sizeof(int));
	}
		
	for (int i = min(nInputRec1X1, nInputRec1X2) + 1001;
		i <= max(nInputRec1X1, nInputRec1X2) + 1000; i++)
		for (int j = min(nInputRec1Y1, nInputRec1Y2) + 1001;
			j <= max(nInputRec1Y1, nInputRec1Y2) + 1000; j++)
			ppnMat[j][i] = 1;

	for (int i = min(nInputRec2X1, nInputRec2X2) + 1001;
		i <= max(nInputRec2X1, nInputRec2X2) + 1000; i++)
		for (int j = min(nInputRec2Y1, nInputRec2Y2) + 1001;
			j <= max(nInputRec2Y1, nInputRec2Y2) + 1000; j++)
			ppnMat[j][i] = 1;


	for (int i = min(nInputRec3X1, nInputRec3X2) + 1001;
		i <= max(nInputRec3X1, nInputRec3X2) + 1000; i++)
		for (int j = min(nInputRec3Y1, nInputRec3Y2) + 1001;
			j <= max(nInputRec3Y1, nInputRec3Y2) + 1000; j++)
			ppnMat[j][i] = 0;


	for (int i = 0; i < 2500; i++)
		for (int j = 0; j < 2500; j++)
			if (ppnMat[j][i])
				nAns++;

	printf("%d\n", nAns);










Exit0:

	return 0;
}