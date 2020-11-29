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
const int maxn=1e5+5;
typedef pair<int,int> point;
point s[maxn];
int l,p,n;
bool cmp(point x,point y)
{
	return x.first<y.first;
}
int main()
{
    int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++){
			scanf("%d%d",&s[i].first,&s[i].second);
		}
		cin>>l>>p;
		for(int i=0;i<n;i++){
			int t=l-s[i].first;
			s[i].first=t;
		}
		s[n].first=l,s[n].second=0;
		sort(s,s+n,cmp);
		int i=0,cnt=0;
		priority_queue<int> que;
		while(!que.empty())  que.pop();
		while(i<=n){
			while(p<s[i].first&&!que.empty()){
				p+=que.top();
				que.pop();
				cnt++;
			}
			if(p<s[i].first) break;
			while(s[i].first<=p&&i<=n){
				que.push(s[i].second);
				i++;
			}
		}
//		cout<<p<<endl;
		if(p>=l)  cout<<cnt<<endl;
		else  cout<<"-1"<<endl;
	}
    return 0;
}
