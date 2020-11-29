#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=1000+10;
const int INF=1<<30;
int L,n;
int a[maxn];
int dp[maxn][maxn];
int main()
{
	while(cin>>L)
	{
		if(L==0)  break;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		a[0]=0;a[++n]=L;
		for(int i=0;i<=n;i++)
			dp[i][i]=0;
		for(int l=1;l<=n;l++){
			int i,j,k;
			for(i=0;i<=n-l;i++){
				j=i+l;
				int minx=INF;
				for(k=i+1;k<j;k++){
					int temp=dp[i][k]+dp[k][j]+a[j]-a[i];
					minx=min(temp,minx);
				}
				if(minx!=INF)
					dp[i][j]=minx;
			}
		}
		printf("The minimum cutting is %d.\n",dp[0][n]);
	}
	return 0;
}