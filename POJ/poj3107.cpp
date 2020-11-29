#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=50000+10;
const int INF=1<<30;
int n,cnt,s;
int dp[maxn],f[maxn],vis[maxn];
int head[maxn*2];
struct Node
{
	int to,next,w;
};
Node edge[maxn*2];
void add(int x,int y){
	edge[cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt++;
}
void init(){
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	cnt=0;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
}
int dfs(int v,int fa){
	f[v]=fa;
	dp[v]=1;
	for(int i=head[v];i!=-1;i=edge[i].next){
		int k=edge[i].to;
		if(k!=f[v]){
			dp[v]+=dfs(k,v);
		}
	}
	int ans=n-dp[v];
	for(int i=head[v];i!=-1;i=edge[i].next){
		int k=edge[i].to;
		if(k==f[v])   continue;
		ans=max(ans,dp[k]);
	}
	vis[v]=ans;
	s=min(ans,s);
	return dp[v];
}
int main()
{
	init();
	s=INF;
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		if(vis[i]==s)
			printf("%d ",i);
	}
	printf("\n");
}