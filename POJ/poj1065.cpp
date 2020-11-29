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
const int maxn=5050;
typedef struct p
{
	int l,w;
}p; 
p s[maxn];
int dp[maxn];
int vis[maxn];
bool cmp(p a,p b)
{
	if(a.l==b.l) return a.w<b.w;
	else return a.l<b.l;
}
int n,t;
int main()
{
    cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d%d",&s[i].l,&s[i].w);
		sort(s,s+n,cmp);
		memset(dp,0,sizeof(dp));
		int res=0;
		for(int i=0;i<n;i++)
		{
			dp[i]=1;
			for(int j=0;j<i;j++){
				if(s[j].w>s[i].w)
					dp[i]=max(dp[i],dp[j]+1);
			}
			res=max(res,dp[i]);
		}
		cout<<res<<endl;
	}
    return 0;
}
