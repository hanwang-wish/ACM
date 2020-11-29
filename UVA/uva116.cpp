#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "algorithm"
using namespace std;
const int maxn=100+10;
const int INF=1<<30;
int m,n;
int a[maxn][maxn];
int dp[maxn][maxn];
int Next[maxn][maxn];
int main()
{
	//freopen("uva116.txt","r",stdin);
	//freopen("uva116.out","w",stdout);
	while(cin>>m>>n)
	{
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				cin>>a[i][j];
		memset(Next,0,sizeof(Next));
		int ans=INF,f=0;
		for(int j=n;j>=1;j--){
			for(int i=1;i<=m;i++){
				if(j==n){
					dp[i][j]=a[i][j];
				}else{
					int col[3]={i-1,i,i+1};
					if(i==1) col[0]=m;
					if(i==m) col[2]=1;
					sort(col,col+3);
					dp[i][j]=INF;
					for(int k=0;k<3;k++){
						int v=dp[col[k]][j+1]+a[i][j];
						if(v<dp[i][j]){
							dp[i][j]=v;
							Next[i][j]=col[k];
						}
					}
				}
				if(j==1&&ans>dp[i][j]){
					ans=dp[i][j];
					f=i;
				}
			}
		}
		cout<<f;
		for(int i=Next[f][1],j=2;j<=n;i=Next[i][j],j++)
			cout<<" "<<i;
		cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}