#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "cmath"
#include "queue"
using namespace std;
const int maxn=35;
int a[maxn][maxn],n,vis[maxn][maxn];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
struct node
{
	int x,y;
};
void bfs(int sx,int sy){
	queue<node>q;
	node w;
	w.x=sx,w.y=sy;
	a[sx][sy]=2;
	vis[sx][sy]=1;
	q.push(w);
	while(!q.empty()){
		node t;
		t=q.front();
		q.pop();
		a[t.x][t.y]=2;
		for(int i=0;i<4;i++){
			int nx=t.x+dx[i],ny=t.y+dy[i];
			if(nx<=n&&nx>=1&&ny<=n&&ny>=1&&a[nx][ny]==0&&!vis[nx][ny]){
				node z;
				z.x=nx,z.y=ny;
				vis[z.x][z.y]=1;
				q.push(z);
			}
		}
	}
}
int main()
{
	//freopen("testdata.in","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	int sx,sy;
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==0){
				if(i==1||i==n||j==1||j==n)  continue;
				int cnt=0;
				for(int k=0;k<4;k++){
					if(a[i+dx[k]][j+dy[k]]){
						cnt++;
					}
				}
				if(cnt>=2){flag=1,sx=i,sy=j;break;}
			}
		}
		if(flag)  break;
	}
	//cout<<sx<<" "<<sy<<endl;
	bfs(sx,sy);
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("%d\n",a[i][n]);
	}
	return 0;
}