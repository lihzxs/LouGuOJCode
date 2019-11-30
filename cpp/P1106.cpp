
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-23 14:41
//	Comment		:	OJ(P1106)
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
    string          szInput;
    int             nInputK;
    int             nLength;

    cin >> szInput >> nInputK;
    nLength = szInput.length();

    for (int i = 0; i < szInput.length(); i++)
        szInput[i] -= '0';

    for (int i = 1; i <= nInputK; i++)
    {
        for (int j = 0; j < nLength; j++)
            if (szInput[j] > szInput[j + 1])
            {
                for (int k = j; k < nLength; k++)
                    szInput[k] = szInput[k + 1];
                nLength--;
                break;
            }
    }

    int nFlag = 1;
    for (int i = 0; i < nLength; i++)
    {
        if (szInput[i] == 0 && i != nLength - 1 && nFlag)
            continue;
        printf("%d", szInput[i]);
        nFlag = 0;
    }

Exit0:

    return 0;
}