#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=100;
string res[maxn],a;
int n,ans;
int vis[maxn];
bool judge(string T,string P,int k){
	int len=T.length();
	for(int i=0;i<k;i++){
		if(T[len-k+i]!=P[i])
			return false;
	}
	return true;
}
void add(string &s,string cmp,int k){
	for(int i=k;i<cmp.length();i++) s+=cmp[i];
}
void dfs(string s){
	int x=s.length();
	ans=max(x,ans);
	for(int i=1;i<=n;i++){
		if(vis[i]>=2)  continue;
		int len=res[i].length();
		for(int j=1;j<=len;j++){
			if(judge(s,res[i],j)){
				vis[i]++;
				string temp=s; add(temp,res[i],j);
				dfs(temp);
				vis[i]--;
			}
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>res[i];
	cin>>a;
	ans=0;
	dfs(a);
	cout<<ans<<endl;
}