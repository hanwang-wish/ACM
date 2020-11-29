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
const int maxn=5050;
const int INF=1<<30;

//定义变量
struct edge{
	int to,cost;
};
typedef pair<int,int> P;  //first表示距离,second表示顶点编号
int n,r; //顶点数和边数
vector<edge> g[maxn];
int d[maxn]; //最短路
int d2[maxn];  //次短路

//求次短路
void dijkstra(int s)
{
	priority_queue<P,vector<P>, greater<P> > que;
	fill(d,d+n+1,INF);
	fill(d2,d2+n+1,INF);
	d[s]=0;
	que.push(P(0,s));

	while(!que.empty())
	{
		P p=que.top(); que.pop();
		int v=p.second,dist=p.first; //最短距离和对应顶点编号
		if(d2[v]<dist)  continue;   //到该点的次短路已经完成
		for(int i=0;i<g[v].size();i++){
			edge e=g[v][i];
			int distance=dist+e.cost;
			if(d[e.to]>distance){
				swap(d[e.to],distance);
				que.push(P(d[e.to],e.to));
			}
			if(d2[e.to]>distance&&d[e.to]<distance){
				d2[e.to]=distance;
				que.push(P(d2[e.to],e.to));
			}
		}
	}
}


int main()
{
    while(cin>>n>>r)
	{
		for(int i=0;i<r;i++){
			int x,y,num;
			cin>>x>>y>>num;
			edge e1;
			e1.to=y,e1.cost=num;
			g[x].push_back(e1);
			edge e2;
			e2.to=x,e2.cost=num;
			g[y].push_back(e2);
		}
		dijkstra(1);
		cout<<d2[n]<<endl;
	}
    return 0;
}
