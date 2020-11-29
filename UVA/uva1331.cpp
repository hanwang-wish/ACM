#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "cmath"
using namespace std;
const int maxn=100;
const double INF=1<<30;
int T,n;
int x[maxn],y[maxn];
double dp[maxn][maxn];
double area(int a,int b,int c){
	double res=(double)(1.0/2)*(x[a]*y[b]+x[c]*y[a]+x[b]*y[c]-x[c]*y[b]-x[b]*y[a]-x[a]*y[c]);
	res=fabs(res);
	return res;
}
double judge(int a,int b,int c){
	for(int i=1;i<=n;i++){
		if(i==a||i==b||i==c)   continue;
		double res=area(a,b,i)+area(a,c,i)+area(b,c,i)-area(a,b,c);
		res=fabs(res);
		if(res<=0.01)  return false;
	}
	return true;
}
int main()
{
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&x[i],&y[i]);
		for(int l=2;l<n;l++){
			int i,j,k;
			for(i=1;i<=n-l;i++){
				dp[i][i+1]=0.0;
				j=i+l;
				dp[i][j]=INF;
				for(k=i+1;k<j;k++){
					if(judge(i,j,k)){
						dp[i][j]=min(dp[i][j],max(max(dp[i][k],dp[k][j]),area(i,j,k)));
					}
				}
			}
			//printf("%.1lf\n",dp[1][n]);
		}
		printf("%.1lf\n",dp[1][n]);
	}
	return 0;
}