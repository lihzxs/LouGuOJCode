/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-18 00:26
//	Comment		:	OJ(P1025)
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

void DFS(int nN, int nK, int nCount, int nPre, int nSum, int& nAns)
{
    //cout << "nC " << nCount << " nPre " << nPre << " nSum " << nSum << endl;
    if (nSum > nN)
        return;
    if (nCount == nK - 1)
    {
        if (nN - nSum >= nPre)
            nAns++;
        return;
    }
    for (int i = nPre; i <= nN - nSum; i++)
        DFS(nN, nK, nCount + 1, i, nSum + i, nAns);
}


int main(int argc, char* argv[])
{
    int					nInputN;
    int					nInputK;
    int                 nCount              = 0;
    scanf("%d%d", &nInputN, &nInputK);
    DFS(nInputN, nInputK, 0, 1, 0, nCount);
    printf("%d", nCount);

Exit0:

    return 0;
}