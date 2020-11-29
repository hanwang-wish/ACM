#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=100+10;
const int INF=1<<30;
int n,m;
int a[maxn],sum[maxn];
int dp[maxn][maxn][20];  //max
int f[maxn][maxn][20];  //min
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n+1;i<=2*n;i++)
		sum[i]=sum[n]+sum[i-n];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++)
			for(int z=1;z<=m;z++)
				f[i][j][z]=INF;
	for(int i=1;i<=2*n;i++){
		for(int j=1;j<=2*n;j++){
			dp[i][j][1]=sum[j]-sum[i-1];
			f[i][j][1]=sum[j]-sum[i-1];
			while(dp[i][j][1]<0) dp[i][j][1]+=10;
			dp[i][j][1]%=10;
			while(f[i][j][1]<0)  f[i][j][1]+=10;
			f[i][j][1]%=10;
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=2*n-l;i++){
			int j=i+l;
			for(int k=i;k<j;k++){
				for(int z=2;z<=m;z++)
					dp[i][j][z]=max(dp[i][j][z],dp[i][k][z-1]*dp[k+1][j][1]);
			}
		}
	}
	for(int i=1;i<=2*n;i++)
		for(int z=2;z<=m;z++)
			f[i][i][z]=0;
	for(int l=1;l<=n;l++){
		for(int i=1;i<=2*n-l;i++){
			int j=i+l;
			for(int k=i;k<j;k++){
				for(int z=2;z<=m;z++)
					f[i][j][z]=min(f[i][j][z],f[i][k][z-1]*f[k+1][j][1]);
			}
		}
	}
	int cnt=0,ans=INF;
	for(int i=1;i<=n;i++)
		cnt=max(dp[i][i+n-1][m],cnt);
	for(int i=1;i<=n;i++)
		ans=min(f[i][i+n-1][m],ans);
	cout<<ans<<endl<<cnt<<endl;
}