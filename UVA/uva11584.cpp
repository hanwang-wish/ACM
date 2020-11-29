#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "algorithm"
#include "vector"
using namespace std;
const int maxn=1000+10;
const int INF=1<<30;
char s[maxn];
int T;
int dp[maxn];
bool judge(int i,int j){
	int flag=0;
	while(i<j){
		if(s[i]==s[j]){
			i++,j--;
		}else{
			flag=1; break;
		}
	}
	if(flag)  return false;
	return true;
}
int main()
{
	cin>>T;
	getchar();
	while(T--){
		memset(s,0,sizeof(s));
		char ch=getchar();
		int n=0;
		while(ch!='\n')  s[++n]=ch,ch=getchar();
		dp[1]=1;
		for(int i=1;i<=n;i++){
			int num=-1;
			vector<int> p;
			for(int j=i;j>=1;j--){
				if(judge(j,i)){
					p.push_back(j);
				}
			}
			dp[i]=INF;
			for(int j=0;j<p.size();j++){
				int res=p[j]-1;
				dp[i]=min(dp[i],dp[res]+1);
			}
			//cout<<dp[n]<<endl;
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}