#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=60+10;
const int maxm=32000+10;
int N,m;
int dp[maxm];
int v1[maxn],p1[maxn],v2[maxn],p2[maxn];
int v[maxn],p[maxn];
int main()
{
	cin>>N>>m;
	for(int i=0;i<62;i++){
		v1[i]=0,p1[i]=0,v2[i]=0,p2[i]=0,v[i]=0,p[i]=0;
	}
	for(int i=1;i<=m;i++){
		int a,b,q;
		cin>>a>>b>>q;
		if(q!=0){
			if(v1[q]==0){
				v1[q]=a;
				p1[q]=b;
			}else{
				v2[q]=a;
				p2[q]=b;
			}
		}else{
			v[i]=a;
			p[i]=b;
		}
	}
	int mx=0;
	for(int i=1;i<=m;i++){
		for(int j=N;j>=v[i];j--){
			dp[j]=max(dp[j],dp[j-v[i]]+v[i]*p[i]);
			if(j>=(v[i]+v1[i]))
				dp[j]=max(dp[j],dp[j-v[i]-v1[i]]+v[i]*p[i]+v1[i]*p1[i]);
			if(j>=(v[i]+v2[i]))
				dp[j]=max(dp[j],dp[j-v[i]-v2[i]]+v[i]*p[i]+v2[i]*p2[i]);
			if(j>=(v[i]+v1[i]+v2[i]))
				dp[j]=max(dp[j],dp[j-v[i]-v1[i]-v2[i]]+v[i]*p[i]+v1[i]*p1[i]+v2[i]*p2[i]);
			mx=max(mx,dp[j]);
		}
	}
	cout<<mx<<endl;
}