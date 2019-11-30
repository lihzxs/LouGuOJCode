/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-24 15:48
//	Comment		:	OJ(P5143)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <list>
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

typedef struct SDate
{
	int			nX;
	int			nY;
	int			nZ;
}SDate;


bool Cmp(const SDate& sFirst, const SDate& sSecond)
{
	return sFirst.nZ < sSecond.nZ;
}


int main(int argc, char* argv[])
{

	int				nInputN;
	double			fAns				= 0;
	SDate*			psDate				= NULL;

	scanf("%d", &nInputN);
	psDate = (SDate*)malloc((nInputN + 1) * sizeof(SDate));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d%d%d", &psDate[i].nX, &psDate[i].nY, &psDate[i].nZ);

	psDate[0].nX = 0;
	psDate[0].nY = 0;
	psDate[0].nZ = 0;
	sort(psDate + 1, psDate + nInputN + 1, Cmp);


	for (int i = 2; i <= nInputN; i++)
		fAns += sqrt((psDate[i].nX - psDate[i - 1].nX) * (psDate[i].nX - psDate[i - 1].nX) +
		(psDate[i].nY - psDate[i - 1].nY) * (psDate[i].nY - psDate[i - 1].nY) +
			(psDate[i].nZ - psDate[i - 1].nZ) * (psDate[i].nZ - psDate[i - 1].nZ));


	printf("%.3f", fAns);



Exit0:

	return 0;
}