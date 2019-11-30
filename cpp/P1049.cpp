/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-27 16:05
//	Comment		:	OJ(P1049)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;





int main(int argc, char* argv[])
{
    int					nInputV;


    int					nInputN;
    int                 nInputTemp;


    int*				pnBagFrom				= NULL;

    scanf("%d", &nInputV);
    scanf("%d", &nInputN);


    pnBagFrom = (int*)malloc((nInputV + 1) * sizeof(int));

    memset(pnBagFrom, 0, (nInputV + 1) * sizeof(int));

    for (int i = 0; i < nInputN; i++)
    {
        scanf("%d", &nInputTemp);
        for (int j = nInputV; j >= nInputTemp; j--)
            pnBagFrom[j] = max(pnBagFrom[j],
                    pnBagFrom[j - nInputTemp] + nInputTemp);
    }





    printf("%d", nInputV - pnBagFrom[nInputV]);




    Exit0:

    return 0;
}