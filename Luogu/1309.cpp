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
#include<cctype>
using namespace std;
const int maxn=200020;
typedef struct node{
	int start,num,id;
}node;
node p[maxn],w[maxn],f[maxn];
int n,r,q;
inline bool cmp(const node&  a,const node& b)
{
	if(a.start==b.start)
		return a.id<b.id;
	return a.start>b.start;
}
int main()
{
    while(cin>>n>>r>>q)
	{
		int N=2*n;
		for(int i=1;i<=N;i++){
			scanf("%d",&p[i].start);
			p[i].id=i;
		}
		for(int i=1;i<=N;i++){
			scanf("%d",&p[i].num);
		}
		sort(p+1,p+1+N,cmp);
		while(r){
			--r;
			for(int i=1;i<=n;i++){
				if(p[i*2].num>p[i*2-1].num){
					p[i*2].start++;
					w[i]=p[i*2];
					f[i]=p[i*2-1];
				}else{
					p[i*2-1].start++;
					w[i]=p[i*2-1];
					f[i]=p[i*2];
				}
			}
			merge(w+1,w+1+n,f+1,f+1+n,p+1,cmp);
		}
		cout<<p[q].id<<endl;
	}
    return 0;
}
