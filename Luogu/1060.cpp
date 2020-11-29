#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=30;
const int maxm=30000+10;
int n,m;
int w[maxn],v[maxn];
int dp[maxm];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>w[i]>>v[i];
	for(int i=1;i<=m;i++){
		for(int j=n;j>w[i];j--){
			dp[j]=max(dp[j],dp[j-w[i]]+(w[i]*v[i]));
		}
	}
	cout<<dp[n]<<endl;
}