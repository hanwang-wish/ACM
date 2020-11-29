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
const int maxn=100010;
const int mod=100003;
int a[maxn];
int dp[maxn];
int n,k;
int main()
{
    while(cin>>n>>k)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++)
			{
				if(i<=j){
					++dp[i]; break;
				}
				else
					dp[i]=(dp[i]+dp[i-j])%mod;
			}
		}
		cout<<dp[n]<<endl;
	}
    return 0;
}
