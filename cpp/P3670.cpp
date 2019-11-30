/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-17 23:09
//	Comment		:	OJ(P3670)
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
    int					nInputM;
    int					nCount				= 0;
    int					nAddItem;
    int*				ppnStore			= NULL;
    string*				pszMat				= NULL;
    string              szTemp;
    map<string, bool>   mp;
    scanf("%d%d", &nInputN, &nInputM);

    pszMat = new string[2 * nInputN + 1];
    for (int i = 1; i <= 2 * nInputN; i++)
        cin >> pszMat[i];


    for (int i = 0; i < nInputM; i++)
        for (int j = i + 1; j < nInputM; j++)
            for (int k = j + 1; k < nInputM; k++)
            {
                nAddItem = 1;
                mp.clear();
                for (int z = 1; z <= nInputN; z++)
                {
                    szTemp.clear();
                    szTemp.push_back(pszMat[z][i]);
                    szTemp.push_back(pszMat[z][j]);
                    szTemp.push_back(pszMat[z][k]);
                    mp[szTemp] = true;
                }

                for (int z = nInputN + 1; z <= 2 * nInputN; z++)
                {
                    szTemp.clear();
                    szTemp.push_back(pszMat[z][i]);
                    szTemp.push_back(pszMat[z][j]);
                    szTemp.push_back(pszMat[z][k]);
                    if (mp[szTemp])
                    {
                        nAddItem = 0;
                        break;
                    }
                }
                nCount += nAddItem;
            }

    printf("%d", nCount);

    Exit0:

    return 0;
}