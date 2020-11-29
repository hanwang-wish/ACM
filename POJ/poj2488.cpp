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
const int maxn=26;
typedef struct P
{
	int x,y;
}P;
P point[maxn];
int vis[maxn][maxn];
int p,q,flag;
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};
void dfs(int x,int y,int step)
{
	if(step==p*q){
		for(int i=0;i<step;i++)
			printf("%c%d",point[i].x+'A',point[i].y+1);
		printf("\n");
		flag=1;
	}
	else
	for(int i=0;i<8;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0&&nx<q&&ny>=0&&ny<p&&!vis[nx][ny]&&!flag){
			vis[nx][ny]=1;
			point[step].x=nx,point[step].y=ny;
			dfs(nx,ny,step+1);
			vis[nx][ny]=0;
		}
	}
}
int main()
{
    int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		scanf("%d %d",&p,&q);
		flag=0;
		memset(vis,0,sizeof(vis));
		vis[0][0]=1;
		point[0].x=0,point[0].y=0;
		printf("Scenario #%d:\n",cas);
		dfs(0,0,1);
		if(!flag) printf("impossible\n");
		printf("\n");
	}
    return 0;
}
