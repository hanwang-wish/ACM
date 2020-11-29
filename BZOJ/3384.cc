#include "bits/stdc++.h"
using namespace std;
const int maxn=1001;
int T,w,a[maxn],dp[maxn][31][2];
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&T,&w);
    for(int i=1;i<=T;i++){
        scanf("%d",&a[i]);
        --a[i];
    }
    int mx=0;
    if(a[1]==0) dp[1][0][0]=1;
    else dp[1][1][1]=1;
    mx=max(mx,max(dp[1][1][1],dp[1][0][0]));
    for(int i=2;i<=T;i++){
        for(int j=0;j<=w;j++){
            for(int k=0;k<=1;k++){
                dp[i][j][k]=dp[i-1][j][k]+(a[i]==k);
                if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][1-k]+(a[i]==k));
                mx=max(mx,dp[i][j][k]);
            }
        }
    }
    printf("%d\n",mx);
    return 0;
}
