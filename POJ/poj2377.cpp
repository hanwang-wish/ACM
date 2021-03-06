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
const int maxn=20020;
int  par[maxn],rankl[maxn];

void init(int n)
{
	for(int i=0;i<=n;i++)
	{
		par[i]=i;
		rankl[i]=0;
	}
}
int findl(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x]=findl(par[x]);
}
void unite(int x,int y)
{
	x=findl(x);
	y=findl(y);
	if(x==y)  return;
	if(rankl[x]<rankl[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rankl[x]==rankl[y])   rankl[x]++;
	}
}
bool same(int x,int y)
{
	return findl(x)==findl(y);
}
int n,m;
struct edge{
	int u,v,cost;
};
bool cmp(const edge e1,const edge e2){
	return e1.cost<e2.cost;
}
edge es[maxn];
int ans;
int kruskal()
{
	sort(es,es+m+1,cmp);
	init(n);
	int res=0;
	for(int i=0;i<m;i++){
		edge e=es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			res+=e.cost;
			ans++;
		}
	}
	return res;
}
int main()
{
    while(cin>>n>>m)
	{
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			es[i].u=a,es[i].v=b,es[i].cost=-c;
		}
		ans=0;
		int cnt=0-kruskal();
	//	cout<<ans<<endl;
		if(ans==n-1)
		cout<<cnt<<endl;
		else
		cout<<"-1"<<endl;
	}
    return 0;
}
