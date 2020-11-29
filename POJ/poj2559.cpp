#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<cctype>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
const int maxn=100000+10;
int h[maxn];
int n;
int main()
{
	while(cin>>n)
	{
		if(n==0)  break;
		for(int i=1;i<=n;i++){
			scanf("%d",&h[i]);
		}
		stack<int> s;
		s.push(0); h[++n]=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			while(h[i]<h[s.top()]){
				long long a=h[s.top()]; s.pop();
				long long b=i-s.top()-1;
				ans=max(ans,a*b);
			}
			s.push(i);
		}
		cout<<ans<<endl;
	}
}