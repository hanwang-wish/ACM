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
const int maxn=25020;
typedef struct P
{
	int start,over;
}P;
P p[maxn];
bool cmp(P a,P b)
{
	if(a.start==b.start)
		return a.over<b.over;
	else
		return a.start<b.start;
}
int N,T;
int main()
{
    while(cin>>N>>T)
	{
		for(int i=0;i<N;i++)
			scanf("%d%d",&p[i].start,&p[i].over);
		sort(p,p+N,cmp);
		int i=0,ans=0,t=0;
		int mx=0;
		while(i<N&&t<T)
		{
			ans++;
			if(p[i].start>t+1){
				cout<<"-1"<<endl;
				return 0;
			}
			while(i<N&&p[i].start<=t+1){
				mx=max(mx,p[i].over);
				i++;
			}
			t=mx;
		}
		if(t>=T)
			cout<<ans<<endl;
		else
			cout<<"-1"<<endl;
	}
    return 0;
}
