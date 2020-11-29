#include "bits/stdc++.h"
using namespace std;
const int maxn=100+1;
int n,m;
char s[maxn][maxn];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
int cnt=0;
void dfs(int x,int y){
    if(s[x][y]=='.') return;
    s[x][y]='.';
    for(int i=0;i<8;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>n||nx<=0||ny<=0||ny>m||s[nx][ny]=='.') continue;
        dfs(nx,ny);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>s[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='W'){
                dfs(i,j);
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}