#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=550;
int g[maxn][maxn];  //记录是否存在边
int res[maxn];  //记录拓扑序列
int edge[maxn];  //记录入度
int n,m;
void topo(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j])
				edge[j]++;
		}
	}
	for(int i=1;i<=n;i++){
		int k=1;
		while(edge[k]!=0) k++;
		res[i]=k;
		edge[k]=-1;
		for(int j=1;j<=n;j++)
			if(g[k][j])
				edge[j]--;
	}
}
int main()
{
	while(cin>>n>>m)
	{
		memset(g,0,sizeof(g));
		memset(res,0,sizeof(res));
		memset(edge,0,sizeof(edge));
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			g[x][y]=1;
		}
		topo();
		for(int i=1;i<n;i++)
			printf("%d ",res[i]);
		printf("%d\n",res[n]);
	}
}