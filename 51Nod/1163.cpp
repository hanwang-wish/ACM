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
const int maxn=50500;
typedef struct p
{
	int e,w;
}p;
p s[maxn];
bool cmp(p a,p b)
{
	return a.e<b.e;
}
int main()
{
    int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>s[i].e>>s[i].w;
		sort(s,s+n,cmp);
		priority_queue<int,vector<int>,greater<int> > que;
		for(int i=0;i<n;i++)
		{
			if(s[i].e>que.size())
			{
				que.push(s[i].w);
			}else if(s[i].e==que.size())
			{
				int t=que.top();
				if(t<s[i].w)
				{
					que.pop();
					que.push(s[i].w);
				}
			}
		}
		long long sum=0;
		while(!que.empty())
		{
			sum+=que.top();
			que.pop();
		}
		cout<<sum<<endl;
	}
    return 0;
}
