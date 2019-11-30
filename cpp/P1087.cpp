/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-9 22:30
//	Comment		:	OJ(P1087)
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

using namespace std;
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

typedef struct SNode
{
	char		cOutput;
	SNode*		psLNode;
	SNode*		psRNode;
}SNode;

SNode* Build(string szTemp)
{
	BOOL		bIsEqual = true;
	for (int i = 0; i < szTemp.length() - 1; i++)
		if (szTemp[i] != szTemp[i + 1])
		{
			bIsEqual = false;
			break;
		}
	SNode* psNode = (SNode*)malloc(sizeof(SNode));
	if (bIsEqual)
	{
		if (szTemp[0] == '0')
			psNode->cOutput = 'B';
		else
			psNode->cOutput = 'I';
	}
	else
		psNode->cOutput = 'F';
	if (szTemp.length() == 1)
		psNode->psLNode = NULL;
	else
		psNode->psLNode = Build(szTemp.substr(0, szTemp.length() / 2));
	if (szTemp.length() == 1)
		psNode->psRNode = NULL;
	else
		psNode->psRNode = Build(szTemp.substr(szTemp.length() / 2, szTemp.length() / 2));
	return psNode;
}

void Print(SNode* psRoot)
{
	if (psRoot == NULL)
		return;
	Print(psRoot->psLNode);
	Print(psRoot->psRNode);
	cout << psRoot->cOutput;
}



int main(int argc, char* argv[])
{
	int				nInputN;
	string			szInput;
	cin >> nInputN >> szInput;

	Print(Build(szInput));

Exit0:

	return 0;
}