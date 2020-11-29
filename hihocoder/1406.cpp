#include "bits/stdc++.h"
using namespace std;
const int maxn=200+10;
const int INF=2e9;
int dp[maxn][maxn],n;
int main()
{
    scanf("%d",&n);
    for(int l=2;l<=n;l++){
        for(int i=1;i+l-1<=n;i++){
            int j=i+l-1;
            dp[i][j]=INF;
            for(int k=i;k<=j;k++){
                int s=0;
                if(k-1>i) s=max(s,dp[i][k-1]);
                if(k+1<j) s=max(s,dp[k+1][j]);
                dp[i][j]=min(dp[i][j],s+k);
            }
        }
    }
    printf("%d\n",dp[1][n]);
}
