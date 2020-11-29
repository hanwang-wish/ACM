#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=200+10;
const int INF=1<<30;
int f[maxn][maxn]; //max
int dp[maxn][maxn]; //min
int sum[maxn],a[maxn];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n+1;i<=2*n;i++)
		sum[i]=sum[n]+sum[i-n];
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++)
			dp[i][j]=INF;
	for(int i=1;i<=2*n;i++)  dp[i][i]=0;
	for(int l=1;l<=n;l++){
		for(int i=1;i<=2*n-l;i++){
			int j=i+l;
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	memset(f,0,sizeof(f));
	for(int l=1;l<=n;l++){
		for(int i=1;i<=2*n-l;i++){
			int j=i+l;
			for(int k=i;k<j;k++){
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	int cnt=0,ans=INF;
	for(int i=1;i<=n;i++)
		cnt=max(f[i][i+n-1],cnt);
	for(int i=1;i<=n;i++)
		ans=min(dp[i][i+n-1],ans);
	cout<<ans<<endl<<cnt<<endl;
}