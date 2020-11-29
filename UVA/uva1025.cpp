#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=1000+100;
const int maxm=10000+100;
const int INF=1<<30;
int n,T,m1,m2;
int t[maxn],d[maxn],e[maxn];
int dp[maxm][60],vis[maxm][60][3];
int main()
{
	int cas=0;
	while(cin>>n)
	{
		if(n==0) break;
		cin>>T;
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		memset(t,0,sizeof(t));
		for(int i=1;i<n;i++)
			cin>>t[i];
		cin>>m1;
		for(int i=1;i<=m1;i++)
			cin>>d[i];
		cin>>m2;
		for(int i=1;i<=m2;i++)
			cin>>e[i];
		//从左到右
		for(int i=1;i<=m1;i++){
			int cnt=d[i];
			for(int j=1;j<=n;j++){
				vis[cnt][j][0]=1;
				cnt+=t[j];
			}
		}
		//从右到左
		for(int i=1;i<=m2;i++){
			int res=e[i];
			for(int j=n;j>=1;j--){
				vis[res][j][1]=1;
				res+=t[j-1];
			}
		}

		for(int i=1;i<n;i++) dp[T][i]=INF;
		dp[T][n]=0;
		for(int i=T-1;i>=0;i--){
			for(int j=1;j<=n;j++){
				dp[i][j]=dp[i+1][j]+1;
				if(j<n&&vis[i][j][0]&&(i+t[j]<=T))   //从左到右
					dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
				if(j>1&&vis[i][j][1]&&(i+t[j-1]<=T))
					dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
			}
		}
		printf("Case Number %d: ",++cas);
		if(dp[0][1]>=INF)  cout<<"impossible"<<endl;
		else  cout<<dp[0][1]<<endl;

	}
	return 0;
}