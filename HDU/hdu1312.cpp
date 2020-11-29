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
const int maxn=30;
char s[maxn][maxn];
int n,m;
int cnt;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
void dfs(int x,int y)
{
	int nx,ny;
	if(x>n||x<0||y>m||y<0) return;
	s[x][y]='#';
	for(int i=0;i<4;i++)
	{
		nx=x+dx[i],ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<m&&s[nx][ny]!='#')
		{
			cnt++;
			dfs(nx,ny);
		}
	}
}
int main()
{
    while(cin>>m>>n)
	{
		if(n+m==0)  break;
		for(int i=0;i<n;i++)
			cin>>s[i];
		 cnt=0;
		int sx,sy;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(s[i][j]=='@')
				{
					sx=i,sy=j; break;
				}
			}
		dfs(sx,sy);
		cnt++;
		cout<<cnt<<endl;
	}
    return 0;
}
