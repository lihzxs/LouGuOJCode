/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-29 16:13
//	Comment		:	OJ(P1033)
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
#define	MAXNUM		201
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	double			fH;
	double			fS;
	double			fV;
	double			fL;
	double			fK;
	double			fDis;
	double			fTimeMax;
	double			fTimeMin;
	int				nN;
	int				nLeft;
	int				nRight;
	int				nAns			= 0;
	
	cin >> fH >> fS >> fV >> fL >> fK >> nN;
	fTimeMax = sqrt(fH / 5.0);
	fTimeMin = sqrt((fH - fK)/ 5.0);
	nRight = (int)(fS - fTimeMin * fV + fL);
	nLeft = (int)(fS - fTimeMax * fV);

	nLeft = max(nLeft, 0);
	nRight = min(nRight, nN);
	cout << nRight - nLeft;


Exit0:

	return 0;
}