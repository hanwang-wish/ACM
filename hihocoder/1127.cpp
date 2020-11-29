#include "bits/stdc++.h"
using namespace std;
const int maxn=1000+100;
vector<int>g[maxn];
int n,m;
int link[maxn];
bool vis[maxn];
bool dfs(int u){
    for(auto v:g[u]){
        if(!vis[v]){
            vis[v]=1;
            if(link[v]==-1||dfs(link[v])){
                link[v]=u; return true;
            }
        }
    }
    return false;
}
int hungary(){
    int res=0;
    memset(link,-1,sizeof(link));
    for(int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        if(dfs(i)) res++;
    }
    return res;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    printf("%d\n%d\n",hungary()/2,n-hungary()/2);
    return 0;
}