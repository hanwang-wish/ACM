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
const int maxn=2020;
typedef struct point
{
	int num,id;
}point;
point a[maxn],b[maxn];
//int a[maxn],b[maxn];
int m,n,k,l,d;
bool cmp1(const point a,const point b)
{
	return a.num>b.num;
}
bool cmp2(const point a,const point b)
{
	return a.id<b.id;
}
int main()
{
    while(cin>>m>>n>>k>>l>>d)
	{
		for(int i=0;i<maxn;i++)
		{
			a[i].id=b[i].id=i;
			a[i].num=b[i].num=0;
		}
		for(int i=0;i<d;i++)
		{
			int x,y,p,q,h;
			scanf("%d%d%d%d",&x,&y,&p,&q);
			if(x==p){
				h=min(y,q);
				b[h].num++;
			}
			if(y==q)
			{
				h=min(x,p);
				a[h].num++;
			}
		}
		sort(a,a+maxn,cmp1);
		sort(b,b+maxn,cmp1);
		sort(a,a+k,cmp2);
		sort(b,b+l,cmp2);
		for(int i=0;i<k;i++){
			cout<<a[i].id<<" ";
		}
		cout<<endl;
		for(int i=0;i<l;i++)
		{
			cout<<b[i].id<<" ";
		}
		cout<<endl;
	}
    return 0;
}
