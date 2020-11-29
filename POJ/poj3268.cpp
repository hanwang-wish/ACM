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
const int INF=1<<25;
const int maxn=1010;
struct edge{
	int to,cost;
};
typedef pair<int,int> P;
vector<edge> g[maxn];
int d[maxn];
int dp[maxn][maxn];
int n,m,x;
void dijkstra(int s)
{
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d,d+n+1,INF);
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();  que.pop();
		int v=p.second;
		if(d[v]<p.first)  continue;
		for(int i=0;i<g[v].size();i++){
			edge e=g[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
int main()
{
    while(cin>>n>>m>>x)
	{
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=INF;
		for(int i=0;i<m;i++)
		{
			edge e;
			int a,b,num;
			scanf("%d%d%d",&a,&b,&num);
			e.to=b,e.cost=num;
			g[a].push_back(e);
		}
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=1;j<=n;j++)
				dp[i][j]=d[j];
		}
		int cnt;
		int mx=0;
		for(int i=1;i<=n;i++){
			cnt=0;
			cnt+=dp[i][x];
			cnt+=dp[x][i];
			mx=max(cnt,mx);
		}
		cout<<mx<<endl;
	}
    return 0;
}
