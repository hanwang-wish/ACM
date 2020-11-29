#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
const int maxn=45050;
int T,M,H;
typedef pair<long long,long long> P;
P p[maxn];
long long mod_pow(long long x,long long n,long long mod)
{
	long long res=1;
	while(n>0)
	{
		if(n&1)  res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int main()
{
    cin>>T;
	while(T--)
	{
		cin>>M>>H;
		for(int i=0;i<H;i++)
			cin>>p[i].first>>p[i].second;
		long long cnt=0;
		for(int i=0;i<H;i++)
		{
			cnt=(cnt+mod_pow(p[i].first,p[i].second,M))%M;
		}
		cout<<cnt<<endl;
	}
    return 0;
}
