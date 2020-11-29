#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=35;
typedef long long LL;
LL a[maxn],h[maxn][maxn];
int n;
LL gcd(LL x,LL y){
	return y ? gcd(y,x%y):x;
}
int main()
{
	//freopen("in.txt","r",stdin);
	while(cin>>n){
		if(n==0) break;
		memset(a,0,sizeof(a));
		memset(h,0,sizeof(h));
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				h[i][j]=a[i]-j+1;
				int k=i+1;
				while(a[k]>=j) h[i][j]++,k++;
			}
		}
		LL sum1=1,sum2=1,cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				sum1*=(++cnt),sum2*=h[i][j];
				LL tmp=gcd(sum1,sum2);
				sum1/=tmp,sum2/=tmp;
			}
		}
		printf("%lld\n",sum1/sum2);
	}
	return 0;
}