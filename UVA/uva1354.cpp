#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "vector"
using namespace std;
const int maxn=15;
int T,s,vis[1<<maxn]; 
double r,w[maxn],sum[1<<maxn];
struct Tree{
	double L,R;
	Tree():L(0),R(0){};
};
vector<Tree> tree[1<<maxn];

void dfs(int subset){
	if(vis[subset])  return;
	vis[subset]=1;
	int flag=0;
	for(int left=(subset-1)&subset;left;left=(left-1)&subset){
		flag=1;
		int right=left^subset;
		double d1=sum[right]/sum[subset];
		double d2=sum[left]/sum[subset];
		dfs(left); dfs(right);
		for(int i=0;i<tree[left].size();i++){
			for(int j=0;j<tree[right].size();j++){
				Tree t;
				t.L=max(tree[left][i].L+d1,tree[right][j].L-d2);
				t.R=max(tree[left][i].R-d1,tree[right][j].R+d2);
				if(t.L+t.R<r)  tree[subset].push_back(t);
			}
		}
	}
	if(!flag)  tree[subset].push_back(Tree());
}
int main()
{
	scanf("%d",&T);
	while(T--){
		scanf("%lf%d",&r,&s);
		for(int i=0;i<s;i++)
			cin>>w[i];
		for(int i=0;i<1<<s;i++){
			tree[i].clear();
			sum[i]=0;
			for(int j=0;j<s;j++){
				if(i&(1<<j)){
					sum[i]+=w[j];
				}
			}
		}
		int root=(1<<s)-1;
		memset(vis,0,sizeof(vis));
		dfs(root);
		double ans=-1;
		for(int i=0;i<tree[root].size();i++)
			ans=max(ans,tree[root][i].L+tree[root][i].R);
		if(ans==-1)
			printf("-1\n");
		else
			printf("%.10lf\n",ans);
	}
}