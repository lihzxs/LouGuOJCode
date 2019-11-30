/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 21:22
//	Comment		:	OJ(P2689)
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
#include <vector>
#include <map>
using namespace std;
#define	MAXNUM		2000
#define	EPS         1e-8

#define ERROR_ID    0

#define PROCESS_ERROR(Condition)    \
{                                   \
        if (!(Condition))           \
        {                           \
            goto Exit0;             \
        }                           \
}


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputX1;
	int				nInputX2;
	int				nInputY1;
	int				nInputY2;
	int				nInputN;
	int				nXSum		= 0;
	int				nYSum		= 0;
	int				nDisX;
	int				nDisY;
	string			szInput;
	char			chTempX;
	char			chTempY;

	scanf("%d%d", &nInputX1, &nInputY1);
	scanf("%d%d", &nInputX2, &nInputY2);
	scanf("%d", &nInputN);

	nDisX = nInputX2 - nInputX1;
	nDisY = nInputY2 - nInputY1;

	if (nDisX <= 0)
		chTempX = 'W';
	else
		chTempX = 'E';

	if (nDisY <= 0)
		chTempY = 'S';
	else
		chTempY = 'N';


	for (int i = 0; i < nInputN; i++)
	{
		cin >> szInput;
		if (szInput[0] == chTempX)
			nXSum++;
		if (szInput[0] == chTempY)
			nYSum++;
	}

	if (abs(nDisX) <= nXSum && abs(nDisY) <= nYSum)
		printf("%d", abs(nDisX) + abs(nDisY));
	else
		printf("-1");



	


Exit0:

	return 0;
}




