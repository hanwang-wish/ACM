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
string s;
long long gcd(long long a,long long b)
{
	if(b==0)   return a;
	return gcd(b,a%b);
}
int main()
{
    while(cin>>s)
	{
		if(s=="0")  break;
		string digit=s.substr(2,s.length()-5);
		int n=digit.length();
		long long m=atoi(digit.c_str());  //小数点后面的数
		long long fmmin,fzmin;
		fmmin=1<<30;
		for(int i=1;i<=n;i++)
		{
			string cnt=digit.substr(0,n-i);
			long long res=m-atoi(cnt.c_str()); //分子
			long long ans=pow(10,n)-pow(10,n-i);  //分母
			long long num=gcd(res,ans);
			res/=num;     //最简形式
			ans/=num;
			if(fmmin>ans)
			{
				fmmin=ans;
				fzmin=res;
			}		
		}
		cout<<fzmin<<"/"<<fmmin<<endl;
	}
    return 0;
}
