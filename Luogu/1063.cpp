#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=200+10;
int a[maxn];
int dp[maxn][maxn];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=2*n-l;i++){
			int j=i+l;
			for(int k=i;k<j;k++){
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+(a[i]*a[k+1]*a[j+1]));
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt=max(cnt,dp[i][i+n-1]);
	cout<<cnt<<endl;
}