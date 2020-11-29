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
#define INF 0x3ffff
using namespace std;
const int maxn=40050;
int a[maxn];
int dp[maxn];
int n,t;
int main()
{
    cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		fill(dp,dp+n,INF);
		for(int i=0;i<n;i++){
			*lower_bound(dp,dp+n,a[i])=a[i];
		}
		cout<<lower_bound(dp,dp+n,INF)-dp<<endl;
	}
    return 0;
}
