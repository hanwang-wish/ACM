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
int n;
int main()
{
    while(cin>>n)
	{
		priority_queue<double>que; //优先队列默认从大到小的顺序
		for(int i=0;i<n;i++)
		{
			double x;
			cin>>x;
			que.push(x);
		}
		double t1,t2,t;
		while(que.size()!=1)
		{
			t1=que.top();
			que.pop();
			t2=que.top();
			que.pop();
			t=2*sqrt(t1*t2);
			que.push(t);
		}
		printf("%.3lf\n",que.top());
	}
    return 0;
}
