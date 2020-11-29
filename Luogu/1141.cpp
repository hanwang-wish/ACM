#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "queue"
using namespace std;
const int maxn=1010;
int vis[maxn][maxn],s[maxn][maxn],n,m,ans[maxn*maxn],num;
struct node{int x,y;};
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int bfs(int sx,int sy){
	queue<node>que;
	node t;
	t.x=sx,t.y=sy;
	int sum=0;
	sum++,num++;
	vis[sx][sy]=num;
	que.push(t);
	while(!que.empty()){
		node u=que.front();
		que.pop();
		for(int i=0;i<4;i++){
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if(nx<1||nx>n||ny<1||ny>n||vis[nx][ny])  continue;
			if(s[nx][ny]!=s[u.x][u.y]){
				node tt;
				tt.x=nx,tt.y=ny;
				vis[nx][ny]=num;
				sum++;
				que.push(tt);
			}
		}
	}
	ans[num]=sum;
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		string str;
		cin>>str;
		for(int j=1;j<=n;j++) s[i][j]=str[j-1]-'0';
	}
	num=0;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(!vis[x][y]){
			cout<<bfs(x,y)<<endl;
		}else{
			cout<<ans[vis[x][y]]<<endl;
		}
	}
	return 0;
}