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
const int maxn=2020;
int dp[maxn][maxn];
char s[maxn];
int n,m;
int vis[30];
int main()
{
    while(cin>>n>>m)
	{
		cin>>s;
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			char c;
			int start,over;
			cin>>c>>start>>over;
			vis[c-'a']=min(start,over);
		}
		for(int i=m-1;i>=0;i--)
		{
			for(int j=i+1;j<m;j++)
			{
				if(s[i]==s[j])
					dp[i][j]=dp[i+1][j-1];
				else
					dp[i][j]=min(dp[i+1][j]+vis[s[i]-'a'],dp[i][j-1]+vis[s[j]-'a']);
			}
		}
		cout<<dp[0][m-1]<<endl;
	}
    return 0;
}
