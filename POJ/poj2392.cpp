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
const int maxn=40040;
int dp[maxn];
typedef struct p
{
	int h,a,c;
}p;
p s[401];
int n;
bool cmp(p x,p y)
{
	return x.a<y.a;
}
int main()
{
    while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>s[i].h>>s[i].a>>s[i].c;
		memset(dp,-1,sizeof(dp));
		sort(s,s+n,cmp);
		dp[0]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<=s[i].a;j++){
				if(dp[j]>=0){
					dp[j]=s[i].c;
				}else if(j<s[i].h||dp[j-s[i].h]<=0)
					dp[j]=-1;
				else
					dp[j]=dp[j-s[i].h]-1;
			}
		}
		int k;
		for(int i=s[n-1].a;i>=0;i--){
			if(dp[i]>=0){
				k=i; break;
			}
		}
		cout<<k<<endl;
	}
    return 0;
}
