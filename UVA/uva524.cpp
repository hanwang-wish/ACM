#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;
const int maxn=25;
int a[maxn];
int vis[maxn];
int n;
bool prime(int x){
	if(x==2)
		return true;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}
void dfs(int n,int cur){
	if(cur==n&&prime(a[0]+a[n-1])){
		for(int i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
	}
	else{
		for(int i=2;i<=n;i++){
			if(!vis[i]&&prime(a[cur-1]+i)){
				a[cur]=i;
				vis[i]=1;
				dfs(n,cur+1);
				vis[i]=0;
			}
		}
	}
}
int main()
{
	int cnt=0;
	while(cin>>n)
	{
		if(cnt++)
			printf("\n");
		printf("Case %d:\n",cnt);
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		a[0]=1;
		vis[1]=1;
		dfs(n,1);
	}
	return 0;
}