/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-1 22:13
//	Comment		:	OJ(P2009)
//
///////////////////////////////////////////

//#include "pch.h"
#include<bits/stdc++.h>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

struct SWheel
{
	int		x;
	int		y;
	int		r;
	int		IsMove;
	long long		nVup;
	long long		nVdown;
}p[10005];

int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }

int q[10005], headd, teill;

int main(int argc, char* argv[])
{
	int			nInputT;
	int			nInputN;
	long long	llDis;
	long long	llR;
	long long			nTemp;
	SWheel		sTemp;
	int			left[1005];
	int			right[1005];
	int			num[1005];

	scanf("%d", &nInputT);
	while (nInputT--)
	{
		int x;
		scanf("%d", &nInputN);
		for (int i = 1; i <= nInputN; i++)
		{
			scanf("%d%d%d", &p[i].x, 
				&p[i].y, &p[i].r);

		}
		memset(left, 0, sizeof(left));
		left[1] = 1;
		right[1] = 1;
		num[1] = 1;

		headd = 0;
		teill = 0;
		q[teill++] = 1;
		while (headd != teill)
		{
			x = q[headd++];
			
			for (int i = 1; i <= nInputN; i++)
			{
				if (x != i && !left[i] && (long long)((p[i].x - p[x].x)*(p[i].x - p[x].x) + (p[i].y - p[x].y)*(p[i].y - p[x].y)) == (long long)(p[i].r + p[x].r)*(p[i].r + p[x].r)) 
				{
					left[i] = left[x] * p[x].r;
					right[i] = right[x] * p[i].r;
					num[i] = (num[x] == 1 ? 0 : 1);
					int g = gcd(left[i], right[i]);
					left[i] /= g;
					right[i] /= g;
					q[teill++] = i;
				}

			}///for (int j = 0; j < nInputN; j++)
		}

		printf("1 clockwise\n");
		for (int i = 2; i <= nInputN; i++) {
			if (!left[i])printf("not moving\n");
			else {
				if (right[i] == 1) {
					printf("%d ", left[i]);
				}
				else {
					printf("%d/", left[i]);
					printf("%d ", right[i]);
				}
				if (num[i])printf("clockwise\n");
				else printf("counterclockwise\n");
			}
		}


	}


Exit0:

	return 0;
}