#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=55;
long long dp[maxn][maxn];
int n;
void init(int m){
	for(int i=0;i<=m;i++)
		dp[i][0]=1;
	for(int i=0;i<=m;i++)
		dp[i][i]=1;
	for(int i=2;i<=m;i++){
		for(int j=1;j<i;j++)
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
	}
}
int main()
{
	cin>>n;
	init(2*n);
	cout<<dp[2*n][n]/(n+1)<<endl;
}