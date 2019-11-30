/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-24 16:58
//	Comment		:	OJ(P1347)
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
	queue<int>			qTopu;
	map<int, int>		mpNum;
	map<int, int>		mpChar;
	int					nInputN;
	int					nInputM;
	int					nStrat;
	int					nEnd;
	int					nTemp;
	vector<int>*		vecMat = NULL;
	int*				pnEnter = NULL;
	int*				pnEnterCla = NULL;
	string				szTemp;
	int					nCount = 1;
	int					nQsize = 0;
	vector<int>			vecAns;


	scanf("%d%d", &nInputN, &nInputM);

	vecMat = new vector<int>[nInputN + 1];
	pnEnter = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnEnter, 0, (nInputN + 1) * sizeof(int));
	pnEnterCla = (int*)malloc((nInputN + 1) * sizeof(int));


	for (int i = 0; i < nInputM; i++)
	{
		cin >> szTemp;
		if (szTemp[0] == szTemp[2])
		{
			printf("Inconsistency found after %d relations.", i + 1);
			return 0;
		}
		if (!mpNum.count(szTemp[0]))
			mpNum[szTemp[0]] = nCount++;
		if (!mpNum.count(szTemp[2]))
			mpNum[szTemp[2]] = nCount++;
		nStrat = mpNum[szTemp[0]];
		nEnd = mpNum[szTemp[2]];
		mpChar[nStrat] = szTemp[0];
		mpChar[nEnd] = szTemp[2];
		vecMat[nStrat].push_back(nEnd);
		pnEnter[nEnd]++;

		memcpy(pnEnterCla, pnEnter, (nInputN + 1) * sizeof(int));
			int nC = 0;
			int	nSum = 0;
			for (int i = 1; i <= nInputN; i++)
				if (pnEnterCla[i] == 0 && mpChar.count(i))
				{
					qTopu.push(i);
					nSum++;
					vecAns.push_back(i);
				}
			while (!qTopu.empty())
			{
				nQsize = qTopu.size();
				nC++;
				while (nQsize--)
				{
					nTemp = qTopu.front();
					qTopu.pop();
					for (int j = 0; j < vecMat[nTemp].size(); j++)
					{
						pnEnterCla[vecMat[nTemp][j]]--;

						if (pnEnterCla[vecMat[nTemp][j]] == 0)
						{
							nSum++;
							qTopu.push(vecMat[nTemp][j]);
							vecAns.push_back(vecMat[nTemp][j]);
						}
					}
				}
			}
			if (nC == nInputN)
			{
				printf("Sorted sequence determined after %d relations: ", i + 1);
				for (int i = 0; i < vecAns.size(); i++)
					printf("%c", mpChar[vecAns[i]]);
				printf(".\n");
				return 0;
			}
			else if (nSum != nCount - 1)
			{
				printf("Inconsistency found after %d relations.", i + 1);
				return 0;
			}
			vecAns.clear();

	}


	printf("Sorted sequence cannot be determined.\n");






Exit0:
	return 0;
}