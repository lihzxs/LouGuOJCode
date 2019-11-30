/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-20 16:24
//	Comment		:	OJ(P5315)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <set>
#include <list>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		20000
#define	EPS         0.0001
#define DIRNUM		4
#define ERROR_ID    0

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int							nInputN;
	int							nInputL;
	int							nInputG;
	int							nInputW;
	int							nInputH;

	scanf("%d%d%d", &nInputN, &nInputL, &nInputG);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nInputW, &nInputH);

		while (nInputW > nInputG || nInputH > nInputG)
		{
			nInputW /= 2;
			nInputH /= 2;
		}

		if (nInputW < nInputL || nInputH < nInputL)
			printf("Too Young\n");
		else if (nInputW != nInputH)
			printf("Too Simple\n");
		else
			printf("Sometimes Naive\n");
	}


	

Exit0:

	return 0;
}

