#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "cmath"
using namespace std;
const int maxn=1e4+100;
double s[maxn];
int n,k;
bool judge(double x){
	int num=0;
	for(int i=1;i<=n;i++){
		num+=(int)(s[i]/x);
	}
	if(num>=k) return true;
	return false;
}
int main()
{
	cin>>n>>k;
	double mx=0.0;
	for(int i=1;i<=n;i++){
		scanf("%lf",&s[i]);
		mx=max(mx,s[i]);
	}
	double l=0.0,r=mx+1,mid,ans;
	for(int i=0;i<100;i++){
		mid=(l+r)/2.0;
		if(judge(mid)){
			l=mid;
			ans=mid;
		}else r=mid;
	}
	printf("%.2f\n",floor(r*100)/100);
}