#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "queue"
using namespace std;
const int maxn=200;
int s[3],t[3];
int dx[]={-1,1,0,0,0};
int dy[]={0,0,-1,1,0};
int ind[maxn];
int g[maxn][5];
int d[maxn][maxn][maxn];
bool conflict(int a,int b,int a2,int b2){
	return a2==b2||(a2==b&&b2==a);
}
typedef struct
{
	int a,b,c;
}Node;
int bfs()
{
	queue<Node> que;
	memset(d,-1,sizeof(d));
	Node f;
	f.a=s[0],f.b=s[1],f.c=s[2];
	d[s[0]][s[1]][s[2]]=0;
	que.push(f);
	while(!que.empty()){
		Node u=que.front(); que.pop();
		int a=u.a,b=u.b,c=u.c;
		if(a==t[0]&&b==t[1]&&c==t[2])  return d[a][b][c];
		for(int i=0;i<ind[a];i++){
			int a2=g[a][i];
			for(int j=0;j<ind[b];j++){
				int b2=g[b][j];
				if(conflict(a,b,a2,b2))  continue;
				for(int k=0;k<ind[c];k++){
					int c2=g[c][k];
					if(conflict(a,c,a2,c2))  continue;
					if(conflict(b,c,b2,c2))  continue;
					if(d[a2][b2][c2]!=-1)  continue;
					Node zz;
					zz.a=a2,zz.b=b2,zz.c=c2;
					d[a2][b2][c2]=d[a][b][c]+1;
					que.push(zz);
				}
			}
		}
	}
	return -1;
}
int main()
{
	int w,h,n;
	while(scanf("%d%d%d\n",&w,&h,&n)==3&&n)
	{
		string str[maxn];
		for(int i=0;i<h;i++)
			getline(cin,str[i]);
		int cnt=0;
		int x[maxn],y[maxn],id[maxn][maxn];
		for(int i=0;i<h;i++){    //建图
			for(int j=0;j<w;j++){
				if(str[i][j]!='#'){
					x[cnt]=i,y[cnt]=j,id[i][j]=cnt;
					if(islower(str[i][j])) s[str[i][j]-'a']=cnt;
					else if(isupper(str[i][j]))  t[str[i][j]-'A']=cnt;
					++cnt;
				}
			}
		}
		for(int i=0;i<cnt;i++){
			ind[i]=0;
			for(int dir=0;dir<5;dir++){
				int nx=x[i]+dx[dir],ny=y[i]+dy[dir];
				if(str[nx][ny]!='#')
					g[i][ind[i]++]=id[nx][ny];
			}
		}
		if(n<=2){
			ind[cnt]=1;g[cnt][0]=cnt; s[2]=t[2]=cnt++;
		}
		if(n<=1){
			ind[cnt]=1;g[cnt][0]=cnt; s[1]=t[1]=cnt++;
		}
		printf("%d\n",bfs());

	}
}