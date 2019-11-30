/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-19 00:24
//	Comment		:	OJ(P1536)
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
int Fin(int* pnSet, int nNum)
{
    if (pnSet[nNum] == nNum)
        return pnSet[nNum];
    else
        return pnSet[nNum] =
                       Fin(pnSet, pnSet[nNum]);
}

int main(int argc, char* argv[])
{
    int				nInputN;
    int				nInputM;
    int*			pnSet			= NULL;
    int				nInputA;
    int				nInputB;
    int				nInputC;
    int             nAns;

    pnSet = (int*)malloc(1001 * sizeof(int));
    while(true)
    {
        nAns = 0;
        scanf("%d", &nInputN);
        if (nInputN == 0)
            break;
        scanf("%d", &nInputM);


        for (int i = 1; i <= nInputN; i++)
            pnSet[i] = i;

        for (int i = 0; i < nInputM; i++)
        {
            scanf("%d%d", &nInputA, &nInputB);
            pnSet[Fin(pnSet, nInputA)] = Fin(pnSet, nInputB);
        }

        for (int i = 1; i <= nInputN; i++)
            if (Fin(pnSet, i) == i)
                nAns++;
        printf("%d\n", nAns - 1);
    }





Exit0:

    return 0;
}