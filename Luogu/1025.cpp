#include "bits/stdc++.h"
using namespace std;
const int maxn=50;
int dp[maxn][maxn],n,m;
int main()
{
	scanf("%d%d",&n,&m);
	dp[0][1]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int x=j-1,y=j+1;
			if(j==1) x=n;
			if(j==n) y=1;
			dp[i][j]=dp[i-1][x]+dp[i-1][y];
		}
	}
	printf("%d\n",dp[m][1]);
	return 0;
}