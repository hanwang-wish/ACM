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
const int maxn=50050;
typedef struct P
{
	int start,over,id;
	friend bool operator<(P a,P b)
	{
		return a.over>b.over;   //小顶堆
	}
}P;
P point[maxn];
bool cmp(P a,P b)
{
	return a.start<b.start;
}
int t[maxn];
int n;
int main()
{
    while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&point[i].start,&point[i].over);
			point[i].id=i;
		}
		int r=0;
		memset(t,0,sizeof(t));
		sort(point,point+n,cmp);
		priority_queue<P> que;
		que.push(point[0]);
		t[point[0].id]=++r;
		for(int i=1;i<n;i++)
		{
			P node=que.top();
			if(node.over<point[i].start){
				t[point[i].id]=t[node.id];
				que.pop();
					que.push(point[i]);
			}
			else{
				t[point[i].id]=++r;
				que.push(point[i]);
			}
		}
		cout<<r<<endl;
		for(int i=0;i<n;i++)
			printf("%d\n",t[i]);
	}
    return 0;
}
