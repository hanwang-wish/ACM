#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "vector"
using namespace std;
const int maxn=20000+10;
const int INF=1<<30;
int T,n;
vector<int> g[maxn];
int wide[maxn],f[maxn],dp[maxn],son[maxn];
int wide_max;
void init(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		g[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
}
void dfs(int v,int fa){
	int d=g[v].size();
	if(fa==-1)
		wide[v]=0;
	else
		wide[v]=wide[fa]+1;
	if(wide_max<wide[v])
		wide_max=wide[v];
	for(int i=0;i<d;i++){
		int k=g[v][i];
		if(k!=fa){
			dfs(k,f[k]=v);
		}
	}
}
void treeDP(int root){
	f[root]=-1;
	wide_max=-1;
	dfs(root,-1);
	for(int i=wide_max;i>=0;i--){
		for(int j=1;j<=n;j++){
			if(wide[j]==i){
				dp[j]=son[j]+1;
				if(i>=1)
					son[f[j]]+=dp[j];
			}
		}
	}
}
int main()
{
	cin>>T;
	while(T--){
		init();
		memset(son,0,sizeof(son));
		memset(dp,0,sizeof(dp));
		treeDP(1);
		int s=INF,pos;
		for(int i=1;i<=n;i++){
			int d=g[i].size();
			int ans=n-dp[i];
			for(int j=0;j<d;j++){
				int k=g[i][j];
				if(k!=f[i]){
					ans=max(ans,dp[k]);
				}
			}
			if(ans<s){
				s=ans;
				pos=i;
			}
		}
		printf("%d %d\n",pos,s);
	}
	return 0;
}