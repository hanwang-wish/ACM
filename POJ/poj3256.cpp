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
int k,n,m;
int t[100];   //记录每次的开始位置
int g[maxn][maxn]; //记录两点之间是否相互可达
int flag[maxn];  //标记访问过的点
int vis[maxn];  //标记这个点被访问了几次
void dfs(int h)
{
	flag[h]=1;
	vis[h]++;
	for(int i=1;i<=n;i++)
	{
		if(!flag[i]&&g[h][i])
			dfs(i);
	}
}
int main()
{
	while(cin>>k>>n>>m)
	{
		for(int i=0;i<k;i++)
			scanf("%d",&t[i]);
		memset(g,0,sizeof(g));
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			g[x][y]=1;
		}
		memset(vis,0,sizeof(vis));
		for(int i=0;i<k;i++)
		{
			memset(flag,0,sizeof(flag));
			dfs(t[i]);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==k)
				cnt++;
		}
		cout<<cnt<<endl;
	}
    return 0;
}
