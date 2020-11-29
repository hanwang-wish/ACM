#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=2e6+100;
const int INF=1<<30;
int K,n;
int dp[maxn],v[100];
int main()
{
	cin>>K>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		ans=max(ans,v[i]);
	}
	int m=2e6;
	for(int i=1;i<=m;i++)
		dp[i]=INF;
	for(int i=1;i<=n;i++){
		for(int j=v[i];j<=m;j++){
			dp[j]=min(dp[j],dp[j-v[i]]+1);
		}
	}
	int res=1;
	for(int i=1;i<=m;i++){
		if(dp[i]>K){
			res=i; break;
		}
	}
	cout<<res-1<<endl;
}