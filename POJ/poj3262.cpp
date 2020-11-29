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
const int maxn=100100;
typedef struct p
{
	int t,d;
	double num;
	friend bool operator<(p a,p b)
	{
		return a.num<b.num;  //大顶堆
	}
}p;
int main()
{
    int n;
	while(cin>>n)
	{
		priority_queue<p> que;
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			p s;
			scanf("%d%d",&s.t,&s.d);
			sum+=s.d;
			s.num=(double)s.d/(double)s.t;
			que.push(s);
		}
		long long cnt=0;
		while(!que.empty())
		{
			p h=que.top();
			que.pop();
			sum-=h.d;
			cnt+=2*sum*h.t;
		}
		cout<<cnt<<endl;
	}
    return 0;
}
