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
const int maxn=10010;
const int INF=1<<30;
int al[maxn],bl[maxn],dl[maxn]; //互相之间喜欢的牛
int ad[maxn],bd[maxn],dd[maxn];  //互相之间讨厌的牛
int n,ml,md;
int d[maxn]; //最短路

void solve()
{
	fill(d,d+n+1,INF);
	d[1]=0;
	for(int k=0;k<n;k++)
	{
		for(int i=1;i<n;i++)
		{
			if(d[i+1]<INF)
				d[i]=min(d[i+1],d[i]);
		}
		for(int i=0;i<ml;i++)
		{
			if(d[al[i]]<INF)
				d[bl[i]]=min(d[bl[i]],d[al[i]]+dl[i]);
		}
		for(int i=0;i<md;i++)
		{
			if(d[bd[i]]<INF)
				d[ad[i]]=min(d[bd[i]]-dd[i],d[ad[i]]);
		}
	}
}

int main()
{
    while(cin>>n>>ml>>md)
	{
		for(int i=0;i<ml;i++){
			scanf("%d%d%d",&al[i],&bl[i],&dl[i]);
		}
		for(int i=0;i<md;i++){
			scanf("%d%d%d",&ad[i],&bd[i],&dd[i]);
		}
		solve();
		int res=d[n];
		if(d[1]<0){
			cout<<"-1"<<endl;
		}else if(res==INF){
			cout<<"-2"<<endl;
		}else
			cout<<res<<endl;
	}
    return 0;
}
