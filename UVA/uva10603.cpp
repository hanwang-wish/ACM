#include "iostream"
#include "cstdio"
#include "cstring"
#include "queue"
#include "algorithm"
using namespace std;
const int maxn=200+10;
int a,b,c,d,T;
int vis[maxn][maxn],ans[maxn],cap[3];  //ans[i]表示杯子中有i升水时对应的最少倒水量
struct Node{
	int v[3],dist;
	bool operator < (const Node & rsh) const{  //小顶堆
		return dist>rsh.dist; 
	}
};

void update(const Node & u){   //更新ans[]
	for(int i=0;i<3;i++){
		int s=u.v[i];
		if(ans[s]<0||u.dist<ans[s])  ans[s]=u.dist;
	}
}

void bfs(int a,int b,int c,int d){
	memset(vis,0,sizeof(vis));
	memset(ans,-1,sizeof(ans));
	cap[0]=a,cap[1]=b,cap[2]=c;
	Node start;
	start.dist=0;
	start.v[0]=0,start.v[1]=0,start.v[2]=c;
	priority_queue<Node>que;
	vis[0][0]=1;
	que.push(start);
	while(!que.empty()){
		Node u=que.top(); que.pop();
		update(u);
		if(ans[d]>=0)  break;   //如果找到了
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++) if(i!=j){   //自己不能和自己匹配
				if(u.v[i]==0||u.v[j]==cap[j])   continue;  
				int num=min(cap[j],u.v[i]+u.v[j])-u.v[j];
				Node u2;
				memcpy(&u2,&u,sizeof(u));
				u2.v[i]-=num;
				u2.v[j]+=num;
				u2.dist=u.dist+num;
				if(!vis[u2.v[0]][u2.v[1]]){  //如果当前状态没有出现过
					vis[u2.v[0]][u2.v[1]]=1;
					que.push(u2);
				}
			}
		}
	}
	while(d>=0){
		if(ans[d]>=0){
			printf("%d %d\n",ans[d],d);
			return ;
		}
		--d;
	}
}
int main()
{
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		bfs(a,b,c,d);
	}
	return 0;
}