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
const int maxn=1002;
const int mod=1000000;
const int maxm=100002;
int vis[maxn];
int t,a,s,b;
int main()
{
    while(cin>>t>>a>>s>>b)
	{
		memset(vis,0,sizeof(vis));
		for(int i=0;i<a;i++)
		{
			int x;
			scanf("%d",&x);
			vis[x-1]++;
		}
		int dp[2][maxm];
		dp[0][0]=1;
		dp[1][0]=1;
		for(int i=0;i<t;i++){
			for(int j=1;j<=b;j++){
				if(j-1-vis[i]>=0)
					dp[(i+1)&1][j]=(dp[(i+1)&1][j-1]+dp[i&1][j]-dp[i&1][j-1-vis[i]]+mod)%mod;
				else{
					dp[(i+1)&1][j]=(dp[(i+1)&1][j-1]+dp[i&1][j])%mod;
				}
			}
		}
		long long cnt=0;
		for(int cas=s;cas<=b;cas++)
		{
			cnt=(cnt+dp[t&1][cas])%mod;
		}
		cout<<cnt%mod<<endl;
	}
    return 0;
}
