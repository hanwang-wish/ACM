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
long long a,p;
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
bool judge(long long n)
{
	int flag=0;
	for(int i=2;i*i<n;i++)
	{
		if(n%i==0){
			flag=1; break;
		}
	}
	if(flag){
		return false;
	}else{
		return true;
	}
}
int main()
{
    while(cin>>p>>a)
	{
		if(p+a==0)  break;
		if(judge(p)){
			cout<<"no"<<endl;
			continue;
		}
		long long yy=a%p;
		long long cnt=mod_pow(a,p,p);
		if(cnt==yy)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
    return 0;
}
