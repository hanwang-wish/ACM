#include "bits/stdc++.h"
using namespace std;
const int maxn=20010;
const int INF=0x3f3f3f3f;
struct node{
    int v,c;
    node(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator <(const node &r)const{
        return c>r.c;
    }
};
struct Edge{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[maxn];
bool vis[maxn];
int dist[maxn];
void Dijkstra(int n,int start){
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++) dist[i]=INF;
    priority_queue<node>que;
    while(!que.empty()) que.pop();
    dist[start]=0;
    que.push(node(start,0));
    while(!que.empty()){
        node tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=0;i<E[u].size();i++){
            int v=E[tmp.v][i].v;
            int cost=E[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u]+cost){
                dist[v]=dist[u]+cost;
                que.push(node(v,dist[v]));
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        E[x].push_back(Edge(y,w));
        E[y].push_back(Edge(x,w));
    }
    Dijkstra(n,1);
    printf("%d\n",dist[n]);
    return 0;
}