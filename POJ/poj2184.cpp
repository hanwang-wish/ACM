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
const int maxn=110;
const int maxm=200001;
const int inf=1<<30;
int s[maxn],f[maxn];
int n;
int dp[maxm];
int main()
{
    while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>s[i]>>f[i];
		for(int i=0;i<=maxm-1;i++)
			dp[i]=-inf;
		dp[100000]=0; //作为智力正负的分界线
		for(int i=0;i<n;i++)
		{
			if(s[i]<0&&f[i]<0) continue; 
			if(s[i]>0)  //考虑智力大于0的情况
			{
				for(int j=maxm-1;j>=s[i];j--)
				{
					if(dp[j-s[i]]>-inf)
						dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
				}
			}else{      //考虑智力小于0的情况
				for(int j=s[i];j<maxm-1+s[i];j++){
					if(dp[j-s[i]]>-inf)
						dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
				}
			}
		}
		int ans=-inf;
		for(int i=100000;i<=maxm-1;i++){
			if(dp[i]>=0)
				ans=max(ans,dp[i]+i-100000);
		}
		cout<<ans<<endl;
	}
    return 0;
}
