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
const int maxn=1010;
int dp[maxn][40];
int a[maxn];
int t,w;
int main()
{
	while(cin>>t>>w)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=t;i++)
			cin>>a[i];
		for(int i=1;i<=t;i++)    //初始化，表示一次都不走的情况
			dp[i][0]=dp[i-1][0]+(a[i]%2);
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=w;j++)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+(a[i]==j%2+1);
		}
		cout<<dp[t][w]<<endl;
	}
    return 0;
}
