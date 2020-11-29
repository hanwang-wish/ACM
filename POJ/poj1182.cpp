#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
const int maxn=50002;
int par[maxn*3],rankl[maxn*3];

//并查集模板
void init(int n){
	for(int i=0;i<n;i++){    //初始化
		par[i]=i;
		rankl[i]=0;
	}
}

int findl(int x){   //查找跟结点
	if(x==par[x]){
		return x;
	}else{
		return par[x]=findl(par[x]);
	}
}

void unite(int x,int y){   //合并操作
	x=findl(x);
	y=findl(y);
	if(x==y) return;
	if(rankl[x]<rankl[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rankl[x]==rankl[y])   rankl[x]++;
	}
}

bool same(int x,int y){   //判断是否在同一集合
	return findl(x)==findl(y);
}

int main()
{
	int n,k;
    cin>>n>>k;
	init(n*3);
	int cnt=0;
	for(int i=0;i<k;i++){
		int id,x,y;
		scanf("%d%d%d",&id,&x,&y);
		--x,--y;
		if(x<0||y<0||n<=x||n<=y){
			cnt++; continue;
		}
		if(id==1){
			if(same(x,y+n)||same(x,y+2*n)){
				cnt++;
			}else{
				unite(x,y);
				unite(x+n,y+n);
				unite(x+2*n,y+2*n);
			}
		}else{
			if(same(x,y)||same(x,y+2*n)){
				cnt++;
			}else{
				unite(x,y+n);
				unite(x+n,y+2*n);
				unite(x+2*n,y);
			}
		}
	}
	cout<<cnt<<endl;
    return 0;
}
