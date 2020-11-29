#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;
const int maxn=50000+10;
const long long INF=-(1e9+1);
long long a[maxn],dp[maxn];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=INF;
	dp[1]=a[1];
	for(int i=2;i<=n;i++){
		dp[i]=max(a[i],dp[i-1]+a[i]);
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
}