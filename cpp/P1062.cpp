/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-19 00:06
//	Comment		:	OJ(P1062)
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
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
    int					nInputN;
    int					nInputK;
    long long           llAns = 0;
    stack<int>          sNum;


    scanf("%d%d", &nInputK, &nInputN);

    while(nInputN != 0)
    {
        sNum.push(nInputN % 2);
        nInputN /= 2;
    }

    while(!sNum.empty())
    {
        llAns += sNum.top() * pow(nInputK, sNum.size() - 1);
        sNum.pop();
    }

    printf("%lld", llAns);



Exit0:

    return 0;
}