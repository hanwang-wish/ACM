#include "iostream"
#include "cstdio"
#include "cstring"
#include "bitset"
#include "algorithm"
using namespace std;
const int maxn=1500+10;
const int maxm=15000+10;
int n,m,ed,ed2;
int ind[maxn]; //入度
int adj[maxm]; //栈顶边对应的顶点
int next1[maxm]; //上一条边的编号
int tail[maxm]; //栈顶边的编号
int vis[maxn];  //存储拓扑排序序列
bitset<maxn>f[maxn];
void add(int x,int y){
	ind[y]++;
	adj[++ed]=y;
	next1[ed]=tail[x];
	tail[x]=ed;
}
int adj2[maxm];
int next2[maxm];
int tail2[maxm];
void add2(int x,int y){
	adj2[++ed2]=y;
	next2[ed2]=tail2[x];
	tail2[x]=ed2;
}
typedef pair<int,int> P;
P p[maxm];
int main()
{
	//freopen("a.txt", "r", stdin);  
    //freopen("b.txt", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)  f[i][i]=1;
	ed=0;
	while(m--){    //数组式邻接表建图
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}

	//构造拓扑排序序列
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(!(ind[i]))
			vis[++cnt]=i;

	int h=1;
	ed2=0;
	while(h<=cnt){
		int a;
		for(int i=tail[a=vis[h++]];i;add2(adj[i],a),i=next1[i])
			if(!(--ind[adj[i]]))
				vis[++cnt]=adj[i];
	}

	int ans=0;
	for(int i=1;i<=n;i++){
		int a;
		for(int j=tail2[a=vis[i]];j;f[a]|=f[adj2[j]],j=next2[j])
			if(!f[a][adj2[j]])
				p[++ans]=P(adj2[j],a);
	}
	sort(p+1,p+1+ans);
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
		printf("%d %d\n",p[i].first,p[i].second);
	return 0;
}