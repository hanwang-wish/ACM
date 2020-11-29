#include "bits/stdc++.h"
using namespace std;
const int maxn=100+10;
typedef long long LL;
LL a[maxn],dp[maxn*10000];
int main()
{
    int n;
    cin>>n;
    LL sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    LL num=(sum+1)/2;
    for(int i=1;i<=n;i++){
        for(int j=num;j>=a[i];j--){
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        }
    }
    LL t=sum-dp[num];
    printf("%lld\n",abs(t-dp[num]));
    return 0;
}
