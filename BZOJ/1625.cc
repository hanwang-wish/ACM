#include "bits/stdc++.h"
using namespace std;
const int maxn=2e4+10;
int n,m,w[3500],v[3500],dp[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&v[i]);
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }
    printf("%d\n",dp[m]);
    return 0;
}