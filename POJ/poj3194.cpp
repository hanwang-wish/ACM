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
const int maxn=120;
int mp[maxn][maxn];
int vis[maxn][maxn];
int n;
int cnt;
int dx[]={-1,1,0,0},dy[]={0,0,1,-1};
void dfs(int x,int y,int k)
{
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<n&&!vis[nx][ny]){
			if(mp[nx][ny]==k)
			{
				cnt++;
				dfs(nx,ny,k);
			}
		}
	}
}
int main()
{
    while(cin>>n)
	{
		if(n==0)  break;
		memset(mp,0,sizeof(mp));
		for(int i=1;i<n;i++)
			for(int j=0;j<n;j++)
			{
				int x,y;
				scanf("%d%d",&x,&y);
				mp[x-1][y-1]=i;
			}
		memset(vis,0,sizeof(vis));
		int num=0;
		for(int k=1;k<n;k++)
		{
			bool flag=false;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cnt=1;
					if(!vis[i][j]&&mp[i][j]==k)
					{
						 dfs(i,j,k);
						 if(cnt==n) num++;
					}
				}
			}
		}
		if(num==n-1) cout<<"good"<<endl;
		else cout<<"wrong"<<endl;
	}
    return 0;
}
