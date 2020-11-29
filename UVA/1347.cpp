#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "cmath"
using namespace std;
const int maxn=10000;
const double INF=1<<30;
struct Node
{
	int x,y;
};
Node p[maxn];
double dp[maxn][maxn];
int n;
double dist(int x1,int y1,int x2,int y2){
	int num=(x1-x2)*(x1-x2);
	int ans=(y1-y2)*(y1-y2);
	double res=sqrt((double)num+(double)ans);
	return res;
}
int main()
{
	while(cin>>n){
		if(n==0)  break;
		for(int i=1;i<=n;i++){
			cin>>p[i].x>>p[i].y;
		}
		for(int i=1;i<=n;i++)
			dp[n][i]=dist(p[i].x,p[i].y,p[n].x,p[n].y);
		for(int i=1;i<=n;i++){
			dp[n-1][i]=dist(p[n-1].x,p[n-1].y,p[n].x,p[n].y)+dist(p[i].x,p[i].y,p[n].x,p[n].y);
		}
		for(int i=n-2;i>=2;i--){
			for(int j=1;j<i;j++)
				dp[i][j]=min(dp[i+1][j]+dist(p[i+1].x,p[i+1].y,p[i].x,p[i].y),dp[i+1][i]+dist(p[j].x,p[j].y,p[i+1].x,p[i+1].y));
		}
		double res=dist(p[1].x,p[1].y,p[2].x,p[2].y)+dp[2][1];
		printf("%.2f\n",res);
	}
	return 0;
}