#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=200;
char s[maxn][maxn],temp[]="yizhong";
int vis[maxn][maxn],n;
int dx[]={1,-1,0,0,-1,-1,1,1};
int dy[]={0,0,1,-1,-1,1,-1,1};
struct Node{int x,y;}c[maxn];
void dfs(int x,int y,Node c[],int k,int cur){
	if(cur==7){
		for(int i=0;i<7;i++)
			vis[c[i].x][c[i].y]=1;
	}else{
		int nx=x+dx[k],ny=y+dy[k];
		if(cur==6||s[nx][ny]==temp[cur+1]){
			c[cur].x=x,c[cur].y=y;
			dfs(nx,ny,c,k,cur+1);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i][j]=='y'){
				for(int k=0;k<8;k++){
					int nx=i+dx[k],ny=j+dy[k];
					if(s[nx][ny]=='i')
						dfs(i,j,c,k,0);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(vis[i][j])  cout<<s[i][j];
			else  cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}