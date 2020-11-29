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
const int inf=2000000000;
const int maxn=100020;
typedef struct p
{
	int score,aid;
}p;
p s[maxn];
int n,c,f;
bool cmp(p a,p b)
{
	return a.score<b.score;
}
int dp1[maxn],dp2[maxn];
int main()
{
    while(cin>>n>>c>>f)
	{
		for(int i=0;i<c;i++)
			scanf("%d%d",&s[i].score,&s[i].aid);
		int sum=0;
		int num=n/2;
		sort(s,s+c,cmp);
		priority_queue<int> que1;
		for(int i=0;i<c;i++){
			if(que1.size()==num)
				dp1[i]=sum;
			else
				dp1[i]=inf;
			sum+=s[i].aid;
			que1.push(s[i].aid);
			if(que1.size()>num){
				int t=que1.top();
				que1.pop();
				sum=sum-t;
			}
		}
			int ans=0;
			priority_queue<int> que2;
			for(int i=c-1;i>=0;i--){
				if(que2.size()==num)
					dp2[i]=ans;
				else
					dp2[i]=inf;
				ans+=s[i].aid;
				que2.push(s[i].aid);
				if(que2.size()>num){
				int h=que2.top();
				que2.pop();
				ans=ans-h;
				}
		}
		int k=-1;
		for(int i=0;i<c;i++){
			if(dp1[i]+dp2[i]+s[i].aid<=f)
			k=s[i].score;
		}
		cout<<k<<endl;
	}
    return 0;
}
