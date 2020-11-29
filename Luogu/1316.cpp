#include "bits/stdc++.h"
using namespace std;
const int maxn=1e5+100;
const int INF=1<<30;
int a[maxn],n,m;
bool judge(int x){
	int ans=a[1],cnt=1;
	for(int i=2;i<=n;i++){
		if(ans+x<=a[i]){
			ans=a[i],cnt++;
		}
	}
	if(cnt>=m) return true;
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int l=0,r=INF,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(judge(mid)) { ans=mid,l=mid+1;}
		else r=mid-1;
	}
	printf("%d\n",ans);
}