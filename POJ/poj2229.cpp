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
const int mod=1000000000;
const int maxn=1001000;
int dp[maxn];
int n;
int main()
{
    while(cin>>n)
	{
		memset(dp,0,sizeof(dp));
		dp[1]=1;
		dp[2]=2;
		for(int i=3;i<=n;i++)
		{
			if(i%2)
				dp[i]=dp[i-1]%mod;
			else
				dp[i]=(dp[i-1]+dp[i/2])%mod;
		}
		cout<<dp[n]<<endl;
	}
	return 0;
    return 0;
}
