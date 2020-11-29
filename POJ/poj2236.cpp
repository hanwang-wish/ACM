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
const int maxn=1010;
int par[maxn],rankl[maxn];

void init(int n){
	for(int i=0;i<=n;i++){
		par[i]=i;
		rankl[i]=0;
	}
}

int findl(int x){
	if(x==par[x])
		return x;
	else{
		return par[x]=findl(par[x]);
	}
}

void unite(int x,int y){
	x=findl(x);
	y=findl(y);
	if(x==y)  return;
	if(rankl[x]<rankl[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rankl[x]==rankl[y])  rankl[x]++;
	}
}

bool same(int x,int y){
	return findl(x)==findl(y);
}

int n,d;
bool judge(int x1,int y1,int x2,int y2){
	if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)>d*d)
		return false;
	else return true;
}

struct p{
	int id,x,y,vis;
}s[maxn];
int main()
{
    cin>>n>>d;
	init(n);
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].y;
		s[i].id=i;
		s[i].vis=0;
	}
	char ch[5];
	while(scanf("%s",ch)!=EOF){
		int a,b;
		if(ch[0]=='O'){
			cin>>a;
			s[a].vis=1;
			for(int i=1;i<=n;i++){
				if(judge(s[i].x,s[i].y,s[a].x,s[a].y)&&s[i].vis&&i!=a)
					unite(i,a);
			}
		}else if(ch[0]=='S'){
			cin>>a>>b;
			if(same(a,b))
				cout<<"SUCCESS"<<endl;
			else
				cout<<"FAIL"<<endl;
		}
	}
    return 0;
}
