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
const int maxn=120;
const int maxm=100002;
int a[maxn],c[maxn];
int dp[maxm];
int n,m;
int main()
{
    while(cin>>n>>m)
	{
		if(n+m==0)  break;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&c[i]);
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				if(dp[j]>=0)
					dp[j]=c[i];
				else if(j<a[i]||dp[j-a[i]]<=0)
					dp[j]=-1;
				else
					dp[j]=dp[j-a[i]]-1;
			}
		}
		int cnt=0;
		for(int i=1;i<=m;i++)
			if(dp[i]>=0)
				cnt++;
		printf("%d\n",cnt);
	}
    return 0;
}
