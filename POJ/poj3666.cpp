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
int a[maxn],b[maxn],c[maxn];
int dp1[maxn][maxn],dp2[maxn][maxn];
int n;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
    while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++){
			b[i]=a[i]; c[i]=a[i];
		}
		sort(b,b+n); //求上升的情况
		sort(c,c+n,cmp); //求下降的情况
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		for(int i=0;i<n;i++){
			int minx=dp1[i][0];
			for(int j=0;j<n;j++){
				minx=min(minx,dp1[i][j]);
				dp1[i+1][j]=minx+abs(a[i]-b[j]);
			}
		}
		int min_up=1000000000;
		for(int i=0;i<n;i++)
			min_up=min(min_up,dp1[n][i]);
		for(int i=0;i<n;i++){
			int miny=dp2[i][0];
			for(int j=0;j<n;j++){
				miny=min(miny,dp2[i][j]);
				dp2[i+1][j]=miny+abs(a[i]-c[j]);
			}
		}
		int min_down=1000000000;
		for(int i=0;i<n;i++)
			min_down=min(min_down,dp2[n][i]);
		cout<<min(min_up,min_down)<<endl;
	}
    return 0;
}
