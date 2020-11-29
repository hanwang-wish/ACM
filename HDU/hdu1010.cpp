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
const int maxn=20;
char s[maxn][maxn];
int vis[maxn][maxn];
int n,m,t;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int flag;
void dfs(int sx,int sy,int gx,int gy,int step)
{
	if(flag)  return;
	if(sx==gx&&sy==gy&&step==t){
		flag=1; return;
	}
	int temp=t-step-abs(sx-gx)-abs(sy-gy);  //奇偶剪枝
	if(temp<0||temp%2!=0)  return;
	for(int i=0;i<4;i++)
	{
		int nx=sx+dx[i];
		int ny=sy+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny])
		{
			if(s[nx][ny]!='X'){
				vis[nx][ny]=1;
				dfs(nx,ny,gx,gy,step+1);
				vis[nx][ny]=0;
			}
		}
	}
}
int main()
{
    while(cin>>n>>m>>t)
	{
		if(n+m+t==0)  break;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>s[i][j];
		memset(vis,0,sizeof(vis));
		int sx,sy,gx,gy;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(s[i][j]=='S'){
					sx=i,sy=j;
				}else if(s[i][j]=='D'){
					gx=i,gy=j;
				}
			}
		flag=0;
		vis[sx][sy]=1;
		dfs(sx,sy,gx,gy,0);
		if(flag) cout<<"YES"<<endl;
		else  cout<<"NO"<<endl;
	}
    return 0;
}
