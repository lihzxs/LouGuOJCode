/////
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-23 17:40
//	Comment		:	OJ(P1114)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
    string		szInput;
    int			nAns			 = 0;
    int*		pnLocal			 = NULL;
    map<int, int> mpLocal;
    int*		pnSum			 = NULL;
    int         nInputN;
    int         nTemp;

    scanf("%d", &nInputN);

    pnLocal = (int*)malloc((nInputN + 1) * sizeof(int));
    pnSum = (int*)malloc((nInputN + 1) * sizeof(int));
    memset(pnLocal, 0, (nInputN + 1) * sizeof(int));
    memset(pnSum, 0, (nInputN + 1) * sizeof(int));


    for (int i = 1; i <= nInputN; i++)
    {
        scanf("%d", &nTemp);
        if (nTemp == 0)
            pnSum[i] = pnSum[i - 1] + 1;
        else
            pnSum[i] = pnSum[i - 1] - 1;
    }


    for (int i = 1; i <= nInputN; i++)
    {
        if (mpLocal[pnSum[i]] != 0 || pnSum[i] == 0)
            nAns = max(i - mpLocal[pnSum[i]], nAns);
        else
            mpLocal[pnSum[i]] = i;
    }

    printf("%d", nAns);


Exit0:

    return 0;
}