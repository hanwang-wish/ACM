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
int l,r,c;
const int maxn=50;
typedef struct P
{
	char c;
	int x,y;
	int id;
	int rec;
}P;
P s[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
int ans;
int flag;
int dx[]={-1,1,0,0,0,0},dy[]={0,0,-1,1,0,0},dz[]={0,0,0,0,1,-1};
void bfs(int sx,int sy,int sz,int gx,int gy,int gz)
{
	queue<P>p;
	if(sx==gx&&sy==gy&&sz==gy)
	{
		flag=1;
		ans=0;
    }
	else
	{
		p.push(s[sz][sx][sy]);
		vis[sz][sx][sy]=1;
		int nx=sx,ny=sy,nz=sz;
		while(!p.empty())
		{
			P t=p.front();
			p.pop();
			for(int i=0;i<6;i++)
			{
				nx=t.x+dx[i];
				ny=t.y+dy[i];
				nz=t.id+dz[i];
				if(ny<c&&ny>=0&&nx<r&&nx>=0&&nz>=1&&nz<=l&&!vis[nz][nx][ny])
				{
					vis[nz][nx][ny]=1;
				if(s[nz][nx][ny].c=='.'){
					s[nz][nx][ny].rec=t.rec+1;
					p.push(s[nz][nx][ny]);
				}
				 if(nx==gx&&ny==gy&&nz==gz)
				{
					flag=1;
					ans=min(ans,(t.rec+1));
				}
				}
				}
			}
		}
	}
int main()
{
    while(cin>>l>>r>>c)
	{
		if(l==0&&r==0&&c==0)  break;
		for(int i=1;i<=l;i++)
			for(int j=0;j<r;j++)
				for(int k=0;k<c;k++)
				{
					cin>>s[i][j][k].c;
					s[i][j][k].x=j;
					s[i][j][k].y=k;
					s[i][j][k].id=i;
					s[i][j][k].rec=0;
				}
		int sx,sy,sz,gx,gy,gz;
		for(int i=1;i<=l;i++)
			for(int j=0;j<r;j++)
				for(int k=0;k<c;k++)
				{
					if(s[i][j][k].c=='S')
					{
						sx=j,sy=k,sz=i;
					}else if(s[i][j][k].c=='E'){
						gx=j,gy=k,gz=i;
					}
				}
		memset(vis,0,sizeof(vis));
		ans=0x3ffff;
		flag=0;
		bfs(sx,sy,sz,gx,gy,gz);
		if(flag)
		cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
		else
		cout<<"Trapped!"<<endl;
		}
    return 0;
}
