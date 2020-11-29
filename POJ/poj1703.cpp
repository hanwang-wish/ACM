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
const int maxn=100010;
int par[maxn*2],rankl[maxn*2];
void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;
		rankl[i]=0;
	}
}

int findl(int x){
	if(par[x]==x)  return x;
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

bool same(int x,int y ){
	return findl(x)==findl(y);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		init(n*2);
		getchar();
		char s;
		int a,b;
		while(m--){
			scanf("%c%d%d%*c",&s,&a,&b);
			if(s=='A'){
				if(same(a,b)){
					cout<<"In the same gang."<<endl;
				}
				else if(same(a,b+n)){
					cout<<"In different gangs."<<endl;
				}else{
					cout<<"Not sure yet."<<endl;
				}
			}else{
				unite(a,b+n);
				unite(a+n,b);
			}
		}
	}
    
    return 0;
}
