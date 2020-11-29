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
const int maxn=1500;
int dp[maxn];
typedef struct p
{
	int start,over,value;
}p;
int n,m,r;
bool cmp(p a,p b)
{
	return a.start<b.start;
}
int main()
{
    while(cin>>n>>m>>r)
	{
		p s[maxn];
		for(int i=0;i<m;i++)
		{
			cin>>s[i].start>>s[i].over>>s[i].value;
			s[i].over+=r;
		}
		sort(s,s+m,cmp);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<m;i++)
		{
			dp[i]=s[i].value;
			for(int j=0;j<i;j++){
				if(s[i].start>=s[j].over)
					dp[i]=max(dp[i],dp[j]+s[i].value);
			}
		}
		int mx=0;
		for(int i=0;i<m;i++)
			mx=max(mx,dp[i]);
		cout<<mx<<endl;
	}
    return 0;
}
