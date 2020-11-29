#include "bits/stdc++.h"
using namespace std;
const int maxn=1e4+100;
vector<int>g[maxn];
int n,m,T;
int vis[maxn];
bool dfs(int u){
    for(auto v:g[u]){
        if(!vis[v]){
            vis[v]=-vis[u];
            if(!dfs(v)) return false;
        }else if(vis[u]==vis[v]) return false;
    }
    return true;
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        memset(vis,0,sizeof(vis));
        int flag=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=-1;
                if(!dfs(i)){
                    flag=1; break;
                }
            }
        }
        if(!flag) printf("Correct\n");
        else printf("Wrong\n");
    }
    return 0;
}