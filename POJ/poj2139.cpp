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
const int maxn=500;
const int INF=1<<25;
int n,m;
int dp[maxn][maxn];

void warshall_floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
}
int main()
{
    while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)
					dp[i][j]=INF;
				else
					dp[i][j]=0;
			}
		}
		for(int i=0;i<m;i++)
		{
			int num;
			scanf("%d",&num);
			int d[maxn];
			for(int i=0;i<num;i++)
				scanf("%d",&d[i]);
			for(int i=0;i<num;i++){
				for(int j=i+1;j<num;j++){
					dp[d[i]][d[j]]=1;
					dp[d[j]][d[i]]=1;
				}
			}
		}
		warshall_floyd();
		int minx=INF;
		for(int i=1;i<=n;i++){
			int res=0;
			for(int j=1;j<=n;j++)
				res+=dp[i][j];
			if(res<minx)
				minx=res;
		}
		cout<<minx*100/(n-1)<<endl;

	}
    return 0;
}
