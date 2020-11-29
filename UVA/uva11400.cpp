#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "algorithm"
using namespace std;
const int maxn=1000+10;
const int INF=1<<30;
struct Node{
	int v,k,c,l;
};
Node p[maxn];
int n;
bool cmp(Node a,Node b){
	return a.v<b.v;
}
int sum[maxn];
int dp[maxn];
int main()
{
	while(cin>>n)
	{
		if(n==0)  break;
		for(int i=1;i<=n;i++){
			cin>>p[i].v>>p[i].k>>p[i].c>>p[i].l;
		}
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+p[i].l;
		dp[0]=0;
		for(int i=1;i<=n;i++){
			dp[i]=INF;
			for(int j=0;j<=i;j++){
				dp[i]=min(dp[i],dp[j]+(sum[i]-sum[j])*p[i].c+p[i].k);
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}