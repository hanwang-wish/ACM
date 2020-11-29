#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=1e5+100;
int dp[maxn];
int n,m;
int c[maxn],t[maxn];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i]>>t[i];
	for(int i=1;i<=n;i++){
		for(int j=t[i];j<=m;j++)
			dp[j]=max(dp[j],dp[j-t[i]]+c[i]);
	}
	cout<<dp[m]<<endl;
}