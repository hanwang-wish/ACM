#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=30;
int vis[maxn][maxn];
long long dp[maxn][maxn];
int n,m,x,y;
int main()
{
	cin>>n>>m>>x>>y;
	vis[x][y]=1;
	vis[x+2][y+1]=1;
	vis[x+1][y+2]=1;
	vis[x-1][y+2]=1;
	vis[x-2][y+1]=1;
	vis[x-2][y-1]=1;
	vis[x-1][y-2]=1;
	vis[x+1][y-2]=1;
	vis[x+2][y-1]=1;
	dp[1][0]=1;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=m+1;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
			if(vis[i-1][j-1])
				dp[i][j]=0;
		}
	}
	cout<<dp[n+1][m+1]<<endl;
}