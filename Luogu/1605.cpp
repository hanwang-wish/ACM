#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=15;
int s[maxn][maxn];
int xx[]={0,0,-1,1};
int yy[]={1,-1,0,0};
int n,m,t;
int ans,sx,sy,dx,dy;
int vis[maxn][maxn];
void dfs(int x,int y){
	//cout<<x<<" "<<y<<endl;
	if(x==dx&&y==dy){
		ans++;
	}else{
		for(int i=0;i<4;i++){
			int nx=x+xx[i],ny=y+yy[i];
			if(nx==sx&&ny==sy)  continue;
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny]&&!s[nx][ny]){
				vis[nx][ny]=1;
				dfs(nx,ny);
				vis[nx][ny]=0;
			}
		}
	}
}
int main()
{
	cin>>n>>m>>t;
	cin>>sx>>sy>>dx>>dy;
	ans=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
			s[i][j]=0;
	}
	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		s[x][y]=1;
	}
	dfs(sx,sy);
	cout<<ans<<endl;
}