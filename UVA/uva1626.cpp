#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=100+10;
const int INF=1<<30;
char s[maxn];
int T;
int dp[maxn][maxn];
bool Match(char a,char b){
	if((a=='('&&b==')')||(a=='['&&b==']'))
		return true;
	return false;
}
void dfs(int i,int j){
	if(i>j)  return;
	if(i==j){
		if(s[i]=='('||s[i]==')')  printf("()");
		else  printf("[]");
		return;
	}
	int ans=dp[i][j];
	if(Match(s[i],s[j])&&ans==dp[i+1][j-1]){
		printf("%c",s[i]);
		dfs(i+1,j-1);
		printf("%c",s[j]);
		return;
	}
	for(int k=i;k<j;k++){
		if(ans==dp[i][k]+dp[k+1][j]){
			dfs(i,k);
			dfs(k+1,j);
			return;
		}
	}
}
int main()
{
	cin>>T;
	getchar();
	while(T--){
		getchar();
		int n=0;
		char ch=getchar();
		while(ch!='\n')  s[++n]=ch,ch=getchar();
		for(int i=1;i<=n;i++){
			dp[i][i]=1;
			dp[i+1][i]=0;
		}
		for(int l=1;l<n;l++){
			int i,j,k;
			for(i=1;i<=n-l;i++){
				j=i+l;
				dp[i][j]=INF;
				if(Match(s[i],s[j]))  dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
				for(k=i;k<j;k++)
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
		//cout<<dp[1][n]<<endl;
		dfs(1,n);
		cout<<endl;
		if(T)  cout<<endl;
	}
	return 0;
}