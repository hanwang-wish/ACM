#include "bits/stdc++.h"
using namespace std;
const int maxn=1e5+100;
int a[maxn],n,m;
bool judge(int x){
	int ans=0,cnt=1;
	for(int i=1;i<=n;i++){
		if(ans+a[i]<=x) ans+=a[i];
		else ans=a[i],cnt++;
	}
	if(cnt>m) return true;;
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	int l=1,r=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		l=max(l,a[i]);
		r+=a[i];
	}
	int ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(judge(mid)) l=mid+1;
		else{
			ans=mid,r=mid-1;
		}
	}
	printf("%d\n",ans);
}