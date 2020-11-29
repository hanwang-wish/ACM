#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "map"
#include "set"
#include "vector"
#include "algorithm"
#include "cmath"
using namespace std;
const int INF=30;
const int maxn=30;
char a[maxn];
char t[maxn];
string s;
int minx;
map<char,string>mp;
void dfs(int cur,char B[],char vis[],vector<char> &c,int n){
	if(cur==n){
		int maxn=0;
		int flag=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<(int)mp[B[i]].length();j++){
				int pos;
				for(int k=0;k<n;k++){
					char ch=mp[B[i]][j];
					if(B[k]==mp[B[i]][j]){
						pos=k; break;
					}
				}
				maxn=max(maxn,abs(pos-i));
				if(maxn>minx){
					flag=1; break;
				}
			}
			if(flag) break;
		}
		if(maxn<minx&&!flag){
			minx=maxn;
			c.clear();
			for(int i=0;i<n;i++)
				c.push_back(B[i]);
		}
	}else{
		for(int i=0;i<n;i++){
			int ok=0;
			for(int j=0;j<cur;j++)
				if(vis[i]==B[j]){
					ok=1; break;
				}
			if(!ok){
				B[cur]=vis[i];
				dfs(cur+1,B,vis,c,n);
			}
		}
	}
}

int main()
{
	while(cin>>s)
	{
		if(s[0]=='#')  break;
		int len=s.length();
		int i=0;
		set<char> str;
		while(i<len){
			char ch;
			while(i<len&&s[i]!=':'){
				ch=s[i];
				str.insert(ch);
				i++;
			}
			i++;
			while(i<len&&s[i]!=';'){
				mp[ch]+=s[i];
				str.insert(s[i]);
				i++;
			}
			i++;
		}
		set<char>::iterator set_iter=str.begin();
		int k=0;
		for(;set_iter!=str.end();set_iter++){
			a[k++]=*set_iter;
		}
		minx=INF;
		vector<char> Q;
		dfs(0,t,a,Q,k);
		for(int i=0;i<Q.size();i++){
			printf("%c ",Q[i]);
		}
		printf("-> %d\n",minx);
		for(int i=0;i<k;i++)
			mp[a[i]]="";
	}
}