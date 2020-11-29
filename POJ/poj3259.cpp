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
const int maxn=8000;
const int INF=1<<25;
struct edge{
	int from,to,cost;
};
edge es[maxn];
int n,m,w;
int d[maxn];

bool find_negative_loop(){
	memset(d,0,sizeof(d));
	for(int i=0;i<n;i++){
		for(int j=0;j<m*2+w;j++){
			edge e=es[j];
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;

				if(i==n-1)  return true;
			}
			//cout<<d[e.to]<<endl;
		}
	}
	return false;
}

int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&w);
		for(int i=0;i<m*2;i+=2)
		{
			int s,e,t;
			scanf("%d%d%d",&s,&e,&t);
			es[i].from=s,es[i].to=e,es[i].cost=t;
			es[i+1].from=e,es[i+1].to=s,es[i+1].cost=t;
		}
		for(int i=m*2;i<w+m*2;i++)
		{
			int s,e,t;
			scanf("%d%d%d",&s,&e,&t);
			es[i].from=s,es[i].to=e,es[i].cost=-t;
		}
		if(find_negative_loop())  cout<<"YES"<<endl;
		else  cout<<"NO"<<endl;
	}
    return 0;
}
