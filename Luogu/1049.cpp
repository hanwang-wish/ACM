#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=50;
const int maxm=20000+10;
int a[maxn];
int dp[maxn][maxm];
int n,V;
int ans;
void dfs(int i,int num){
	if(num>=0){
		ans=min(ans,num);
	}else{
		return;
	}
	if(i==n){
		ans=min(ans,num);
		return;
	}
	dfs(i+1,num);
	dfs(i+1,num-a[i+1]);
}
int main()
{
	cin>>V;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//memset(dp,0,sizeof(dp));
	ans=maxm;
	dfs(1,V);
	dfs(1,V-a[1]);
	cout<<ans<<endl;
}