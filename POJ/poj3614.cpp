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
const int maxn=2502;
typedef struct p
{
	int minx,mx;
}p;
p s[maxn];
int vis[maxn];
int c,l;
bool cmp(p a,p b)
{
	return a.mx<b.mx;
}
int main()
{
    while(cin>>c>>l)
	{
		for(int i=0;i<c;i++)
			cin>>s[i].minx>>s[i].mx;
		memset(vis,0,sizeof(vis));
		priority_queue<int,vector<int>, greater<int> > que;
		for(int i=0;i<l;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			for(int i=0;i<y;i++)
				que.push(x);
		}
		sort(s,s+c,cmp);
		int cnt=0;
		while(!que.empty()){
			int t=que.top();
			que.pop();
			for(int i=0;i<c;i++){
				if(!vis[i]&&t>=s[i].minx&&t<=s[i].mx){
					vis[i]=1; cnt++; break;
				}
			}
		}
		cout<<cnt<<endl;
	}
    return 0;
}
