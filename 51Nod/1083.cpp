#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=500+10;
typedef long long LL;
LL dp[maxn][maxn],a[maxn][maxn];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		dp[1][i]=dp[1][i-1]+a[1][i];
	for(int i=1;i<=n;i++)
		dp[i][1]=dp[i-1][1]+a[i][1];
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
		}
	}
	cout<<dp[n][n]<<endl;
}