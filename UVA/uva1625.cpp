#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=5000+10;
const int INF=1<<30;
int T;
int c[maxn][maxn],dp[maxn][maxn];
int main()
{
	scanf("%d",&T);
	getchar();
	while(T--){
		int n=0,m=0;
		char a[maxn],b[maxn];
		char ch=getchar();
		while(ch!='\n') a[++n]=ch,ch=getchar();
		ch=getchar();
		while(ch!='\n')  b[++m]=ch,ch=getchar();
		int p[maxn],q[maxn];
		for(int i=1;i<=n;i++) p[i]=a[i]-'A';
		for(int i=1;i<=m;i++) q[i]=b[i]-'A';
		int sp[50],sq[50],ep[50],eq[50];
		for(int i=0;i<50;i++){
			sp[i]=sq[i]=INF;
			ep[i]=eq[i]=0;
		}
		for(int i=1;i<=n;i++){
			sp[p[i]]=min(sp[p[i]],i);
			ep[p[i]]=i;
		}
		for(int i=1;i<=m;i++){
			sq[q[i]]=min(sq[q[i]],i);
			eq[q[i]]=i;
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(!i&&!j)  continue;
				int v1=INF,v2=INF;
				if(i) v1=dp[i-1][j]+c[i-1][j];
				if(j) v2=dp[i][j-1]+c[i][j-1];
				dp[i][j]=min(v1,v2);
				if(i){
					c[i][j]=c[i-1][j];
					if(sp[p[i]]==i&&sq[p[i]]>j) c[i][j]++;
					if(ep[p[i]]==i&&eq[p[i]]<=j) c[i][j]--;
				}else if(j){
					c[i][j]=c[i][j-1];
					if(sq[q[j]]==j&&sp[q[j]]>i) c[i][j]++;
					if(eq[q[j]]==j&&ep[q[j]]<=i) c[i][j]--;
				}
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}