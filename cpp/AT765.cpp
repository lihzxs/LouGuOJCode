
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

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nN;
	double			fX;
	double			fY;
	int				pnAns[6];
	for (int i = 0; i < 6; i++)
		pnAns[i] = 0;

	scanf("%d", &nN);

	for (int i = 0; i < nN; i++)
	{
		scanf("%lf%lf", &fX, &fY);
		if (fX >= 35)
			pnAns[0]++;
		if (fX >= 30 && fX < 35)
			pnAns[1]++;
		if (fX >= 25 && fX < 30)
			pnAns[2]++;
		if (fY >= 25)
			pnAns[3]++;
		if (fX >= 0 && fY < 0)
			pnAns[4]++;
		if (fX < 0)
			pnAns[5]++;
	}
	for (int i = 0; i < 5; i++)
		printf("%d ", pnAns[i]);

	printf("%d\n", pnAns[5]);

Exit0:

	return 0;
}