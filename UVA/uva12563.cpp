#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=100;
int T,n,w;
int v[maxn];
int vis[maxn*100],dp[maxn*100];
int main()
{
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		cin>>n>>w;
		for(int i=1;i<=n;i++)
			cin>>v[i];
		w-=1;
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		for(int i=n;i>=1;i--){
			for(int j=w;j>=0;j--){
				if(j>=v[i]){
					if(vis[j]<vis[j-v[i]]+1){
						vis[j]=vis[j-v[i]]+1;
						dp[j]=dp[j-v[i]]+v[i];
					}else if(vis[j]==vis[j-v[i]]+1){
						dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
					}
				}
			}
		}
		printf("Case %d: %d %d\n",cas,vis[w]+1,dp[w]+678);
	}
}