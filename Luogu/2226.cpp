#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=10000+10;
int T;
int n;
int vis[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j%i==0)
					vis[j]=!vis[j];
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(vis[i])
				cnt++;
			cout<<cnt<<endl;
	}
}