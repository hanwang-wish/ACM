#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=110;
int dp1[maxn],dp2[maxn];
int n;
int h[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		dp1[i]=1;
		for(int j=1;j<i;j++){
			if(h[j]<h[i]&&dp1[i]<dp1[j]+1)
				dp1[i]=dp1[j]+1;
		}
	}
	for(int i=n;i>=1;i--){
		dp2[i]=1;
		for(int j=i+1;j<=n;j++){
			if(h[j]<h[i]&&dp2[i]<dp2[j]+1)
				dp2[i]=dp2[j]+1;
		}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,(dp1[i]+dp2[i]));
	cout<<(n-(ans-1))<<endl;
	return 0;
}