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
const int maxn=400;
int dp[maxn][maxn];
int a[maxn][maxn];
int n;
int main()
{
    while(cin>>n)
	{
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
				scanf("%d",&a[i][j]);
		}
		dp[1][1]=a[1][1];
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
		}
		int mx=0;
		for(int j=1;j<=n;j++)
			mx=max(dp[n][j],mx);
		cout<<mx<<endl;
	}
    return 0;
}
