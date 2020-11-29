#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "cmath"
#include "algorithm"
using namespace std;
const int maxn=1e5+100;
int n,c;
int x[maxn];
bool judge(int d){
	int pos=1,cnt;
	for(int i=1;i<c;i++){
		cnt=pos+1;
		while(cnt<=n&&x[cnt]-x[pos]<d) cnt++;
		if(cnt==n+1) return false;
		pos=cnt;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&c);
	int mx=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		mx=max(mx,x[i]);
	}
	sort(x+1,x+1+n);
	int l=0,r=mx+1,mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(judge(mid)) {l=mid+1;ans=mid;}
		else r=mid-1;
	}
	printf("%d\n",ans);
}