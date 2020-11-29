#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=1e6+100;
int n,V;
int a[110];
long long dp[maxn];
int main()
{
	cin>>n>>V;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=a[i];j<=V;j++)
			dp[j]=dp[j]+dp[j-a[i]];
	cout<<dp[V]<<endl;
}