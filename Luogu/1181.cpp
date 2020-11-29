#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
const int maxn=100011;
int a[maxn];
int dp[maxn];
int n,m;
int main()
{
    while(scanf("%d",&n)!=EOF){
		scanf("%d",&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(dp[i-1]+a[i]<=m){
				dp[i]=dp[i-1]+a[i];
			}else{
				dp[i]=a[i];
				cnt++;
			}
		}
		printf("%d\n",++cnt);
	}
    return 0;
}
