#include "bits/stdc++.h"
using namespace std;
const int maxn=1000+10;
int n,m;
char s[maxn][maxn];
struct node{
    int x,y;
};
queue<node>que[2];
int vis[2][maxn][maxn];
int dx[]={-1,0,1,0,-1,-1,1,1};
int dy[]={0,-1,0,1,-1,1,-1,1};
bool bfs(int w){
    int sz=que[w].size();
    while(sz--){
        node r=que[w].front(); que[w].pop();
        for(int i=0;i<4+(w?0:4);i++){
            int nx=r.x+dx[i],ny=r.y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m||vis[w][nx][ny]||s[nx][ny]=='#') continue;
            if(vis[w^1][nx][ny]) return true;
            vis[w][nx][ny]=1;
            que[w].push((node){nx,ny});
        }
    }
    return false;
}
int solve(){
    int res=0;
    while(!que[1].empty()||!que[0].empty()){
        res++;
        if(bfs(0)) return res;
        if(bfs(1)) return res;
        if(bfs(1)) return res;
    }
    return -1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>s[i][j];
            if(s[i][j]=='C'){
                que[0].push((node){i,j});
                vis[0][i][j]=1;
            }
            if(s[i][j]=='D'){
                que[1].push((node){i,j});
                vis[1][i][j]=1;
            }
        }
    }
    int ans=solve();
    if(ans==-1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}