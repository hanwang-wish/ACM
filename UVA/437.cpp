#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=100;
int n;
struct Node{
	int x,y,z;
};
Node p[maxn];
int g[maxn][maxn];
bool judge(int a,int b){
	if((min(p[a].x,p[a].y)>min(p[b].x,p[b].y))&&(max(p[a].x,p[a].y)>max(p[b].x,p[b].y)))
		return true;
	return false;
}
int dp[maxn];
int dfs(int i){
	int& ans=dp[i];
	if(ans!=-1)  return ans;
	ans=p[i].z;
	for(int j=1;j<=n;j++){
		if(g[i][j])
			ans=max(ans,dfs(j)+p[i].z);
	}
	return ans;
}
int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("a.out","w",stdout);
	int cas=0;
	while(cin>>n)
	{
		if(n==0) break;
		for(int i=1;i<=n;i++){
			cin>>p[i].x>>p[i].y>>p[i].z;
			p[i+n].x=p[i].y,p[i+n].y=p[i].z,p[i+n].z=p[i].x;
			p[i+2*n].x=p[i].z,p[i+2*n].y=p[i].x,p[i+2*n].z=p[i].y;
		}
		n*=3;
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(judge(i,j))
					g[i][j]=1;
			}
		}
		memset(dp,-1,sizeof(dp));
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,dfs(i));
		}
		printf("Case %d: maximum height = ",++cas);
		cout<<ans<<endl;
	}
}