/////
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-21 23:10
//	Comment		:	OJ(P3958)
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
inline bool Check(long long nX1, long long nY1, long long nZ1,
	long long nX2, long long nY2, long long nZ2, long long nR)
{
	long long		llDis;
	llDis = (nX1 - nX2) * (nX1 - nX2) + (nY1 - nY2) * (nY1 - nY2) +
		(nZ1 - nZ2) * (nZ1 - nZ2);
	if (4 * nR * nR >= llDis)
		return true;
	else
		return false;
}

typedef struct SDate
{
	int	nX;
	int	nY;
	int	nZ;
}SDate;


bool BFS(SDate* psDate, int* pnFlag, int nN, int nR, int nH)
{
	SDate sTemp;
	queue<SDate> qBFS;
	int			nQsize;
	for (int i = 0; i < nN; i++)
	{
		if (psDate[i].nZ <= nR)
		{
			pnFlag[i] = 1;
			qBFS.push(psDate[i]);
		}
	}

	while (!qBFS.empty())
	{
		nQsize = qBFS.size();
		while (nQsize--)
		{
			sTemp = qBFS.front();
			qBFS.pop();
			if (nH - sTemp.nZ <= nR)
				return true;
			for (int i = 0; i < nN; i++)
			{
				if (!pnFlag[i])
				{
					if (Check(sTemp.nX, sTemp.nY, sTemp.nZ,
						psDate[i].nX, psDate[i].nY, psDate[i].nZ, nR))
					{
						pnFlag[i] = 1;
						qBFS.push(psDate[i]);
					}
				}
			}///for (int i = 0; i < nN; i++)

		}
	}
	return false;
}


int main(int argc, char* argv[])
{
	int			nInputT;
	int			nInputN;
	int			nInputH;
	int			nInputR;
	int*		pnFlag				= NULL;
	SDate*		psDate				= NULL;

	psDate = (SDate*)malloc(1006 * sizeof(SDate));
	pnFlag = (int*)malloc(1006 * sizeof(int));
	scanf("%d", &nInputT);

	while (nInputT--)
	{
		scanf("%d%d%d", &nInputN, &nInputH, &nInputR);
		memset(pnFlag, 0, nInputN * sizeof(int));
		for (int i = 0; i < nInputN; i++)
			scanf("%d%d%d", &psDate[i].nX, &psDate[i].nY, 
				&psDate[i].nZ);

		if (BFS(psDate, pnFlag, nInputN, nInputR, nInputH))
			printf("Yes\n");
		else
			printf("No\n");
	}


Exit0:

	return 0;
}