#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "algorithm"
using namespace std;
const int maxn=200+10;
char g[maxn][maxn];
int f[maxn][maxn];
int n,m,x,y,k,l,r,res;
pair<int,int> q[maxn],tmp;
int dx[]={0,-1,1,0,0},dy[]={0,0,0,-1,1};
bool judge(int x,int y){
	if(x>=1&&x<=n&&y>=1&&y<=m)  return true;
	return false;
}
void solve(int x,int y,int d,int len){
	l=r=0;
	for(int i=0;judge(x,y);i++,x+=dx[d],y+=dy[d]){
		if(g[x][y]=='x')   l=r=0;
		else{
			tmp.first=f[x][y],tmp.second=i;
			while(l<r&&q[r-1].first+(i-q[r-1].second)<=tmp.first)  r--;
			q[r++]=tmp;
			while(l<r&&(i-q[l].second)>len)  l++;
			f[x][y]=q[l].first+(i-q[l].second);
			res=max(res,f[x][y]);
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&k);
	for(int i=1;i<=n;i++)
		scanf("%s",g[i]+1);
	memset(f,0x80,sizeof(f)); f[x][y]=0;
	for(int i=1,s,e,d,len;i<=k;i++){
		scanf("%d%d%d",&s,&e,&d); len=e-s+1;
		if(d==1)  for(int j=1;j<=m;j++)  solve(n,j,1,len);
		else if(d==2)  for(int j=1;j<=m;j++)  solve(1,j,2,len);
		else if(d==3)  for(int j=1;j<=n;j++)  solve(j,m,3,len);
		else for(int j=1;j<=n;j++)   solve(j,1,4,len);
	}
	printf("%d\n",res);
}