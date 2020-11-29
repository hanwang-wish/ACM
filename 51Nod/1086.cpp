#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=5e5+10;
int n,m;
int w[maxn],p[maxn],c[maxn];
long long dp[maxn];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&w[i],&p[i],&c[i]);
	int cnt=n;
	for(int i=1;i<=n;i++){
		for(int j=1;;j*=2){
			if(c[i]>=j){
				++cnt;
				w[cnt]=j*w[i],p[cnt]=j*p[i],c[i]-=j;
			}else{
				w[i]=c[i]*w[i],p[i]=p[i]*c[i];break;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=m;j>=w[i];j--){
			dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
		}
	}
	cout<<dp[m]<<endl;
}