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
char s[maxn];
int dp[maxn][maxn];
int n;
int main()
{
    while(cin>>s)
	{
		memset(dp,0,sizeof(dp));
		n=strlen(s);
		for(int i=n-1;i>=0;i--)
		{
			for(int j=i+1;j<n;j++)
			{
				if(s[i]==s[j])
					dp[i][j]=dp[i+1][j-1];
				else
					dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
			}
		}
		cout<<dp[0][n-1]<<endl;
	}
    return 0;
}
