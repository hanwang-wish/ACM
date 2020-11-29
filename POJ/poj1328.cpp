#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
const int maxn=1010;
typedef struct P
{
	double start,over;
}P;
P point[maxn];
bool cmp(P a,P b)
{
	return a.start<b.start;
}
int main()
{
    int n;
	double r;
	int cas=0;
	while(cin>>n>>r)
	{
		if(n==0&&r==0) break;
		int res=0;
		for(int i=0;i<n;i++)
		{
			double x,y;
			cin>>x>>y;
			if(res==-1) continue;
			if(y>r){
				res=-1;
				continue;
			}
			double tt=sqrt(r*r-y*y);
			point[i].start=x-tt;
			point[i].over=x+tt;
		}
		if(res==-1)
		{
			cout << "Case " << ++cas<< ": " << res << endl;
			continue;
		}
		sort(point,point+n,cmp);
		double mi=-0x3ffff;
		for(int i=0;i<n;i++)
		{
			if(mi<point[i].start){
				res++;
				mi=point[i].over;
			}
			else if(mi>point[i].over){
				mi=point[i].over;
			}
		}
		cout << "Case " << ++cas<< ": " << res << endl;
	}
    return 0;
}
