/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-19 13:59
//	Comment		:	OJ(P2649)
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
    int				nInputN;
    int             nInputM;
    int*            pnSeq               = NULL;
    int*            pnFlag              = NULL;
    int             nTemp               = 0;
    int             nAns                = 0;
    scanf("%d%d", &nInputM, &nInputN);

    pnFlag = (int*)malloc((nInputM * nInputN + 1) * sizeof(int));
    memset(pnFlag, 0, (nInputM * nInputN + 1) * sizeof(int));

    pnSeq = (int*)malloc(nInputN * sizeof(int));

    for (int i = 0; i < nInputN; i++)
    {
        scanf("%d", pnSeq + i);
        pnFlag[pnSeq[i]] = 1;
    }


    sort(pnSeq, pnSeq + nInputN);

    for (int i = nInputM * nInputN; i >= 1; i--)
    {
        if (!pnFlag[i])
            nTemp++;
        else if (nTemp > 0)
            nTemp--;
        else
            nAns++;
    }

    printf ("%d", nAns);

Exit0:

    return 0;
}