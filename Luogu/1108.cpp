#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=5000+50;
int dp[maxn],f[maxn],a[maxn];
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(a[j]>a[i]&&dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
		ans=max(dp[i],ans);
	for(int i=0;i<n;i++)
		if(dp[i]==1)
			f[i]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(dp[i]==dp[j]&&a[i]==a[j])
				f[j]=0;
			else if(dp[i]-1==dp[j]&&a[j]>a[i])
				f[i]+=f[j];
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++)
		if(dp[i]==ans)
			cnt+=f[i];
	cout<<ans<<" "<<cnt<<endl;
	return 0;
}