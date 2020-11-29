#include "bits/stdc++.h"
using namespace std;
const int maxn=1000+10;
int a[maxn],n;
typedef long long LL;
LL sum[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		ans+=(n-i+1)*a[i];
	}
	cout<<ans<<endl;
}
