#include "iostream"
#include "cstdio"
#include "cstring"
#include "vector"
using namespace std;
const int maxn=15;

int row[maxn][maxn]; //在第i行填入了num
int col[maxn][maxn]; //在第j列填入了num
int pos[maxn][maxn]; //在(i,j)所对应的方块中填入了num
int res[maxn][maxn]; //记录最终值
typedef struct{
	int r,c;
}point;
vector<point> vis; //记录没有填数的位置

int getpos(int i,int j){  //获取(i,j)所在方块号
	int ii=i/3;
	int jj=j/3;
	return ii*3+jj;
}

void setAll(int i,int j,int num,int f){   //在(i,j)填入num
	row[i][num]=f;
	col[j][num]=f;
	pos[getpos(i,j)][num]=f;
}

bool judge(int i,int j,int num){    //判断(i,j)位置能不能填数
	if((!row[i][num])&&(!col[j][num])&&(!pos[getpos(i,j)][num]))
		return true;
	return false;
}

bool dfs(int n){  //填数
	if(n<0)
		return true;
	for(int i=1;i<=9;i++){
		int x=vis[n].r,y=vis[n].c;
		if(judge(x,y,i)){
			setAll(x,y,i,1);
			res[x][y]=i;
			if(dfs(n-1))
				return true;
			setAll(x,y,i,0);
		}
	}
	return false;
}

int main()
{
	int T;
	cin>>T;
	while(T--){
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		memset(pos,0,sizeof(pos));
		memset(res,0,sizeof(res));
		vis.clear();
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				char ch;
				cin>>ch;
				int cnt=ch-'0';
				if(cnt){
					res[i][j]=cnt;
					setAll(i,j,cnt,1);
				}else{
					point a;
					a.r=i,a.c=j;
					vis.push_back(a);
				}
			}
		}
		if(dfs(vis.size()-1)){
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					printf("%d",res[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}