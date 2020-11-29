#include "bits/stdc++.h"
using namespace std;
const int maxn=200+100;
const int INF=500;
int dp[maxn][maxn],n,a,b,k[maxn];
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dp[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		int x=i-k[i],y=i+k[i];
		if(x>=1) dp[i][x]=1;
		if(y<=n) dp[i][y]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	if(dp[a][b]<INF) printf("%d\n",dp[a][b]);
	else printf("-1\n");
}