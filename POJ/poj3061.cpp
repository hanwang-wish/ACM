#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=1e5+100;
typedef long long LL;
int T,n;
LL a[maxn],sum[maxn],S;
int main()
{
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&S);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		int res=maxn;
		int s=1,t=1,sum=0;
		for(;;){
			while(t<=n&&sum<S) sum+=a[t++];
			if(sum<S) break;
			res=min(res,t-s);
			sum-=a[s++];
		}
		if(res==maxn) printf("0\n");
		else printf("%d\n",res);
	}
	return 0;
}