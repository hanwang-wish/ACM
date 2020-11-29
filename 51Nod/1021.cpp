#include "bits/stdc++.h"
using namespace std;
const int maxn=100+10;
typedef long long LL;
const LL INF=2e9+10;
LL dp[maxn][maxn],a[maxn],sum[maxn];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i+l-1<=n;i++){
            int j=i+l-1;
            dp[i][j]=INF;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    printf("%lld\n",dp[1][n]);
}
