#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "set"
#include "map"
using namespace std;
const int maxn=1e6+100;
const int INF=1<<30;
int p,a[maxn];
int main()
{
	scanf("%d",&p);
	set<int>v;
	for(int i=1;i<=p;i++){
		scanf("%d",&a[i]);
		v.insert(a[i]);
	}
	int n=v.size();
	map<int,int>mp;
	int s=1,t=1,num=0,res=INF;
	for(;;){
		while(t<=p&&num<n){
			if(mp[a[t++]]++==0){
				num++;
			}
		}
		if(num<n) break;
		res=min(res,t-s);
		mp[a[s]]--;
		if(mp[a[s]]==0) num--;
		s++;
	}
	printf("%d\n",res);
}