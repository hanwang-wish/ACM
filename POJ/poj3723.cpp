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
const int maxn=50010;
int n,m,r;
struct edge{
	int u,v,cost;
};
bool cmp(const edge& e1,const edge& e2){
	return e1.cost<e2.cost;
}
edge es[maxn];

//并查集部分
int par[maxn];
int rankl[maxn];
void init(int n){
	for(int i=0;i<=n;i++){
		par[i]=i;
		rankl[i]=0;
	}
}
int findl(int x){
	if(par[x]==x)
		return x;
	else{
		return par[x]=findl(par[x]);
	}
}
void unite(int x,int y){
	x=findl(x);
	y=findl(y);
	if(x==y)  return;
	if(rankl[x]<rankl[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rankl[x]==rankl[y])  rankl[x]++;
	}
}
bool same(int x,int y){
	return findl(x)==findl(y);
}

//最小生成树
int kruskal(){
	sort(es,es+r,cmp);
	init(n+m);
	int res=0;
	for(int i=0;i<r;i++){
		edge e=es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			res+=e.cost;
		}
	}
	return res;
}
int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&r);
		for(int i=0;i<r;i++){
			int x,y,d;
			scanf("%d%d%d",&x,&y,&d);
			es[i].u=x,es[i].v=y+n,es[i].cost=-d;
		}
		printf("%d\n",10000*(n+m)+kruskal());
	}
    return 0;
}
