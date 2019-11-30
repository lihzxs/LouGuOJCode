/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-19 15:07
//	Comment		:	OJ(P1123)
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
int**				ppnGuide		= NULL;

bool Check(int** ppnFlag, int nN, int nM, int nX, int nY)
{
    int nNewX;
    int nNewY;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
        {
            nNewX = nX + i;
            nNewY = nY + j;
            if (nNewX < 1 || nNewX > nN)
                continue;
            if (nNewY < 1 || nNewY > nM)
                continue;
            if (ppnFlag[nNewX][nNewY])
                return false;
        }
    return true;
}



void DFS(int** ppnMat, int** ppnFlag, int nN, int nM,
        int nPreX, int nPreY, int nSum, int& nAns)
{
    nAns = max(nAns, nSum);
    int nNewX;
    int nNewY;

    nNewX = nPreX;
    nNewY = nPreY + 1;
    if (nNewY > nM)
    {
        nNewX = nPreX + 1;
        nNewY = 1;
        if (nNewX > nN)
            return;
    }

    if (Check(ppnFlag, nN, nM, nNewX, nNewY))
        //if (!ppnFlag[i][j])
    {
        ppnFlag[nNewX][nNewY] = 1;
        DFS(ppnMat, ppnFlag, nN, nM,
            nNewX, nNewY, nSum + ppnMat[nNewX][nNewY], nAns);
        ppnFlag[nNewX][nNewY] = 0;
    }
    DFS(ppnMat, ppnFlag, nN, nM,
        nNewX, nNewY, nSum, nAns);


}


int main(int argc, char* argv[])
{
    int             nInputT;
    int				nInputN;
    int             nInputM;
    int**           ppnMat              = NULL;
    int**           ppnFlag             = NULL;
    string          szInput;
    int             nTemp;
    int             nAns;

    ppnGuide = (int**)malloc(4 * sizeof(int*));
    for (int i = 0; i < 4; i++)
        ppnGuide[i] = (int*)malloc(2 * sizeof(int));

    ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
    ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
    ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
    ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;


    ppnMat = (int**)malloc(7 * sizeof(int*));
    for (int i = 1; i <= 6; i++)
        ppnMat[i] = (int*)malloc(7 * sizeof(int));

    ppnFlag = (int**)malloc(7 * sizeof(int*));
    for (int i = 1; i <= 6; i++)
        ppnFlag[i] = (int*)malloc(7 * sizeof(int));

    scanf("%d", &nInputT);

    while (nInputT--)
    {
        scanf("%d%d", &nInputN, &nInputM);
        nAns = 0;
        for (int i = 1; i <= nInputN; i++)
            memset(ppnFlag[i], 0, (nInputM + 1) * sizeof(int));

        for (int i = 1; i <= nInputN; i++)
        {
            for (int j = 1; j <= nInputM; j++)
            {
                scanf("%d", &nTemp);
                ppnMat[i][j] = nTemp;
            }
        }
        DFS(ppnMat, ppnFlag, nInputN, nInputM,
            1, 1, 0, nAns);
        for (int i = 1; i <= nInputN; i++)
            memset(ppnFlag[i], 0, (nInputM + 1) * sizeof(int));
        ppnFlag[1][1] = 1;
        DFS(ppnMat, ppnFlag, nInputN, nInputM,
            1, 1, ppnMat[1][1], nAns);

        printf("%d\n", nAns);

    }



Exit0:

    return 0;
}