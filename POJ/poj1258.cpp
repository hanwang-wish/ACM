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
const int maxn=110;
const int INF=1<<28;
int a[maxn][maxn];
int n;
int mincost[maxn];
bool used[maxn];
int prim()
{
	for(int i=1;i<=n;i++){
		mincost[i]=INF;
		used[i]=false;
	}
	mincost[1]=0;
	int res=0;
	while(true)
	{
		int v=-1;
		for(int u=1;u<=n;u++){
			if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
		}
		if(v==-1)  break;
		used[v]=true;
		res+=mincost[v];
		for(int u=1;u<=n;u++){
			mincost[u]=min(mincost[u],a[v][u]);
		}
	}
	return res;
}
int main()
{
    while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)				
				cin>>a[i][j];
		}
		cout<<prim()<<endl;

	}
    return 0;
}
