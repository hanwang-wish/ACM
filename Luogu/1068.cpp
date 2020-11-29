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
const int maxn=5050;
typedef struct p
{
	int id,score;
}p;
p s[maxn];
int n,m;
bool cmp(const p a,const p b)
{
	if(a.score==b.score)
		return a.id<b.id;
	return a.score>b.score;
}
int main()
{
    while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			cin>>s[i].id>>s[i].score;
		}
		int t=m*1.5;
		sort(s,s+n,cmp);
		int k=s[t-1].score;
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(s[i].score>=k)
				cnt++;
		}
		cout<<k<<" "<<cnt<<endl;
		for(int i=0;i<cnt;i++)
		{
			cout<<s[i].id<<" "<<s[i].score<<endl;
		}
	}
    return 0;
}
